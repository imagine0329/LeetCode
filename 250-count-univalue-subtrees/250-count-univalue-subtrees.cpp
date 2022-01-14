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
    int num;
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        num = 0;
        dfs(root, 0);
        
        return num;
    }
    
    bool dfs(TreeNode* root, int val) {
        if(root == nullptr)
            return true;
        
        if(!dfs(root->left, root->val) | !dfs(root->right, root->val))
            return false;

        num++;
        
        return root->val == val;
    }
};