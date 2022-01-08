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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(nullptr);
        
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            if(root == nullptr)
            {
                ans.push_back(level);
                level.clear();
                q.push(nullptr);
                root = q.front();
                q.pop();
                if(root == nullptr)
                    break;
            }
            
            level.push_back(root->val);
            
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        
        return ans;
    }
};