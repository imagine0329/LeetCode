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
    int traverse(TreeNode* root, int maximum = INT_MIN)
    {
        if(!root)
            return 0;
        
        int left = traverse(root->left, max(root->val, maximum));
        int right = traverse(root->right, max(root->val, maximum));
        int total;
        if(root->val >= maximum)
            total = 1 + left + right;
        else
            total = left + right;
        
        return total;
    }
    
    int goodNodes(TreeNode* root) {
        return traverse(root);
    }
};