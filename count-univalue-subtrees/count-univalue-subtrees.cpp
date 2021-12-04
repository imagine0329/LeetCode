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
    
    bool dfs(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            num++;
            return true;
        }    
        
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        
        if(!(l && r))
            return false;
        
        if((!(root->left) || root->val == root->left->val) &&
           (!(root->right) || root->val == root->right->val))
        {
            num++;
            return true;
        }
        
        return false;
    }
};