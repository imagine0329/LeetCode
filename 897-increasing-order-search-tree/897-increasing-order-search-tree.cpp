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
private:
    TreeNode* curr;
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        return inorder(root, nullptr);
    }
    
    TreeNode* inorder(TreeNode* root, TreeNode* successor) {
        if(root == nullptr)
            return successor;
        
        TreeNode* res = inorder(root->left, root);
        root->left = nullptr;
        root->right = inorder(root->right, successor);
        
        return res;
    }
};