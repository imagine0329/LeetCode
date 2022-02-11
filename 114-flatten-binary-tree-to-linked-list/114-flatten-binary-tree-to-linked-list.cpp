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
        
        if(root->right && root->left) {
            TreeNode* node = root;
            node = node->left;
            while(node && node->right)
                node = node->right;
            if(node) {
                node->right = root->right;
                root->right = nullptr;
            }
        }
        
        if(root->left) {
            root->right = recur(root->left);
            root->left = nullptr;
        }
        else
            recur(root->right);
        
        return root;
    }
};