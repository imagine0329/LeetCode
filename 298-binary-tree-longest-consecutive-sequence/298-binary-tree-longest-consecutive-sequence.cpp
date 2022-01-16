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
    int longestConsecutive(TreeNode* root) {
        int longest = 0;
        dfs(root, 1, longest);
        
        return longest;
    }
    
    void dfs(TreeNode* root, int len, int& longest) {
        if(root == nullptr)
            return;
        
        longest = max(longest, len);
        int left_l, right_l;
        if(root->left && root->left->val == root->val + 1)
            left_l = len + 1;
        else
            left_l = 1;
        
        if(root->right && root->right->val == root->val + 1)
            right_l = len + 1;
        else
            right_l = 1;
            
        dfs(root->left, left_l, longest);
        dfs(root->right, right_l, longest);
    }
};