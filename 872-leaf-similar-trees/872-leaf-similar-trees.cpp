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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1); s2.push(root2);
        
        while(!s1.empty() && !s2.empty()) {
            if(dfs(s1) != dfs(s2))
                return false;
        }
        
        return s1.empty() && s2.empty();
    }
    
    int dfs(stack<TreeNode*>& s) {
        while(true) {
            TreeNode* root = s.top(); s.pop();
            if(root->right) s.push(root->right);
            if(root->left) s.push(root->left);
            if(!root->left && !root->right) return root->val;
        }
    }
};