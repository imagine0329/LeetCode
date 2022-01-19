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
    int diameterOfBinaryTree(TreeNode* root) {
        int longest = INT_MIN;
        height(root, longest);
        return longest;
    }
    
    int height(TreeNode* root, int& longest) {
        if(root == nullptr)
            return 0;
        
        int left = height(root->left, longest);
        int right = height(root->right, longest);
        
        longest = max(longest, left + right);
        
        return max(left, right) + 1;
    }
};