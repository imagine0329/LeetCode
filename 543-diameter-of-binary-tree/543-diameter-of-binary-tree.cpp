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
    int diameterOfBinaryTree(TreeNode* root) {
        int path = 0;
        traverse(root, path);
        return path;
    }
    
    int traverse(TreeNode* root, int& path) {
        if(!root) return 0;
        
        int l = traverse(root->left, path);
        int r = traverse(root->right, path);
        path = max(path, l + r);
        
        return max(l, r) + 1;
    }
};