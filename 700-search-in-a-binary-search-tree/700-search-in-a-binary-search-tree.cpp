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
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root, val);
    }
    
    TreeNode* dfs(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        
        if(root->val == val)
            return root;
        
        auto left = dfs(root->left, val);
        auto right = dfs(root->right, val);
        
        return left ? left : right;
    }
};