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
        return dfs(root, nullptr, 1);
    }
    
    int dfs(TreeNode* root, TreeNode* parent, int length) {
        if(root == nullptr)
            return length;
        
        length = parent && parent->val + 1 == root->val ? length + 1 : 1;
        int left = dfs(root->left, root, length);
        int right = dfs(root->right, root, length);
        
        return max(length, max(left, right));
    }
};