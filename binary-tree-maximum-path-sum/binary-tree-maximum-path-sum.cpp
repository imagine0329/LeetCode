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
    int max_sum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        postorder(root);
        return max_sum;
    }
    
    int postorder(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        auto left = max(postorder(root->left), 0);
        auto right = max(postorder(root->right), 0);
        
        max_sum = max(max_sum, left + right + root->val);
        
        return root->val + max(left, right);
    }
};