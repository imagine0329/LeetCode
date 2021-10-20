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
    TreeNode* inorder(TreeNode* root, TreeNode* tail = nullptr)
    {
        if(!root)    
            return tail;
        
        TreeNode* res = inorder(root->left, root);
        root->left = nullptr;
        root->right = inorder(root->right, tail);
        
        return res;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        return inorder(root);
    }
};