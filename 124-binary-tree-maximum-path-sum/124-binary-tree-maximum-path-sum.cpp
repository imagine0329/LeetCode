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
    int max_sum;
    
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        traverse(root);
        
        return max_sum;
    }
    
    int traverse(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        int left = max(traverse(root->left), 0);
        int right = max(traverse(root->right), 0);
        
        max_sum = max(max_sum, root->val + left + right);
        
        return max(left, right) + root->val;
    }
};