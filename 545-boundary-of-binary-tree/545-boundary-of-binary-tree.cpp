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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        
        ans.push_back(root->val);
        dfs(root->left, true, false, ans);
        dfs(root->right, false, true, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, bool left, bool right, vector<int>& ans) {
        if(!root) return;
        
        if(left || (!left && !right && !root->left && !root->right))
            ans.push_back(root->val);
        
        dfs(root->left, left, right && !root->right, ans);
        dfs(root->right, left && !root->left, right, ans);
        
        if(right)
            ans.push_back(root->val);
    }
};