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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *node = root, *parent = nullptr;
        
        while(node && node->val != key) {
            parent = node;
            if(node->val < key) node = node->right;
            else node = node->left;
        }
        
        if(!node) return root;
        
        if(!node->left || !node->right) {
            TreeNode* child = node->left ? node->left : node->right;
            if(!parent) root = child;
            else if(parent->left == node) parent->left = child;
            else parent->right = child;
        }
        else {
            TreeNode* current = node;
            parent = node, node = node->right;
            while(node->left){
                parent = node;
                node = node->left;
            }
            current->val = node->val;
            if(parent->left == node) parent->left = node->right;
            else parent->right = node->right;
        }
        
        delete node;
        return root;
    }
};