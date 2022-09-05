/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        if(root!=NULL) q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> t;
            for(int i=0;i<size;i++)
            {
                Node * front = q.front();
                q.pop();
                for(auto node : front->children)
                {
                    q.push(node);
                }
                t.push_back(front->val);
            }
            ans.push_back(t);
        }
        return ans;
    }
};