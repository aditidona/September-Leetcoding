/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string solve(TreeNode* root)
    {
        if(root==NULL) return "";
        string ans = to_string(root->val);
        string leftans = solve(root->left);
        if(leftans!="") ans = ans + "(" + leftans + ")";

        string rightans = solve(root->right);
        if(rightans!="")
        {
            if(leftans=="")
            {
                ans = ans + "()" + "(" + rightans + ")";
            }
            else{
                ans = ans + "(" + rightans + ")";
            }
        }
        return ans;

    }
    string tree2str(TreeNode* root)
    {
        string ans;
        ans = solve(root);
        return ans;

    }
};