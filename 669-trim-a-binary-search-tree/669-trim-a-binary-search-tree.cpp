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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        while(root && (root->val < low || root->val > high)) {
            if(root->val < low) root = root->right;
            if(root->val > high) root = root->left;
        }
        
        TreeNode* node = root;
        while(node) {
            while(node->left && node->left->val < low)
                node->left = node->left->right;
            node = node->left;
        }
        
        node = root;
        while(node) {
            while(node->right && node->right->val > high)
                node->right = node->right->left;
            node = node->right;
        }
        
        return root;
    }
};