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
        dfs(root);
        
        return num;
    }
    
    bool dfs(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        bool isUni = false;
        isUni = !(!dfs(root->left) | !dfs(root->right));

        if(isUni && (root->left == nullptr || root->left->val == root->val) && 
          (root->right == nullptr || root->right->val == root->val)) {
            num++;
            return true;
        }
        
        return false;
    }
};