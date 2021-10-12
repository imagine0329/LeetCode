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
    int inorder(TreeNode* root, int low, int high)
    {
        if(root == nullptr)
            return 0;
        
        int left = inorder(root->left, low, high);
        int right = inorder(root->right, low, high);
        if(root->val >= low && root->val <= high)
            return left + right + root->val;
        else
            return left + right;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    }
};