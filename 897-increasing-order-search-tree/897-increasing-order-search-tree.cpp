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
    TreeNode* predecessor;
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(0);
        predecessor = ans;
        
        inorder(root);
        return ans->right;
    }
    
    void inorder(TreeNode* root) {
        if(!root) return;
        
        inorder(root->left);
        
        root->left = nullptr;
        predecessor->right = root;
        predecessor = root;
        
        inorder(root->right);
    }
};