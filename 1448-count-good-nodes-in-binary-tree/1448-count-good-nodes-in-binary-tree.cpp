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
    int goodNodes(TreeNode* root) {
        return traverse(root, INT_MIN);
    }
    
    int traverse(TreeNode* root, int maximum) {
        if(root == nullptr)
            return 0;
        
        int left = traverse(root->left, max(maximum, root->val));
        int right = traverse(root->right, max(maximum, root->val));
        
        return root->val >= maximum ? left + right + 1 : left + right;
    }
};