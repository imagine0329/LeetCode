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
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        traverse(root, maximum);
        return maximum;
    }
    
    int traverse(TreeNode* root, int& maximum) {
        if(!root) return 0;
        
        int l = max(traverse(root->left, maximum), 0);
        int r = max(traverse(root->right, maximum), 0);
        maximum = max(maximum, root->val + l + r);
        
        return max(root->val, max(root->val + l, root->val + r));
    }
};