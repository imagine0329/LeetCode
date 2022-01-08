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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        stack<TreeNode*> s1, s2;
        
        s1.push(root);
        
        while(!s1.empty() || !s2.empty())
        {
            vector<int> level;
            while(!s1.empty())
            {
                root = s1.top();
                s1.pop();
                level.push_back(root->val);
                if(root->left)
                    s2.push(root->left);
                if(root->right)
                    s2.push(root->right);
            }
            
            if(level.size() > 0)
            {
                ans.push_back(level);
                level.clear();
            }
            
            while(!s2.empty())
            {
                root = s2.top();
                s2.pop();
                level.push_back(root->val);
                if(root->right)
                    s1.push(root->right);
                if(root->left)
                    s1.push(root->left);
            }
            
            if(level.size() > 0)
                ans.push_back(level);
        }
        
        return ans;
    }
    
};