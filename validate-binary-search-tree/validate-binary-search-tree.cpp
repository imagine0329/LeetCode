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
    bool isValidBST(TreeNode* root) {
        if(root->left != NULL and root->val <= root->left->val) return false;
        if(root->right != NULL and root->val >= root->right->val) return false;
        
        return validate(root, NULL, NULL);
    }
    
    bool validate(TreeNode* root, int min, int max)
    {
        if(root == NULL) return true;
        if(min != NULL and root->val <= min) return false;
        if(max != NULL and root->val >= max) return false;
        
        return validate(root->left, min, root->val) and validate(root->right, root->val, max);
    }
};