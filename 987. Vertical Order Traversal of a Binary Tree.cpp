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
    void solve(TreeNode *root, int x, int y, map<int, vector<pair<int,int>>> &mp)
    {
        if(root==NULL) return;
        mp[y].push_back(make_pair(x,root->val));
        solve(root->left, x+1, y-1, mp);
        solve(root->right, x+1, y+1, mp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp;
        int x=0;
        int y=0;
        solve(root, x, y, mp);
        for(auto i : mp)
        {
            sort(i.second.begin(),i.second.end());
            vector<int> t;
            for(int j=0;j<i.second.size();j++)
            {
                t.push_back(i.second[j].second);
            }
            ans.push_back(t);
        }
        return ans;
    }
};