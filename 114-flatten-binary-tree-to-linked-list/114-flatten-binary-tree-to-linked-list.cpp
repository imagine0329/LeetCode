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
    void flatten(TreeNode* root) {
        recur(root);
    }
    
    TreeNode* recur(TreeNode* root) {
        if(!root) return nullptr;
        
        if(!root->left && !root->right)
            return root;
        
        TreeNode* left = recur(root->left);
        TreeNode* right = recur(root->right);
        
        if(left) {
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        return right == nullptr ? left : right;
    }
};