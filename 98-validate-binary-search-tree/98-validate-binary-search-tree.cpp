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
        return dfs(root, nullptr, nullptr);
    }
    
    bool dfs(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) return true;
        
        if((min != nullptr && root->val <= min->val) || (max != nullptr && root->val >= max->val))
            return false;
        
        return dfs(root->left, min, root) && dfs(root->right, root, max);
    }
};