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
    bool isSymmetric(TreeNode* root) {
        return traverse(root->left, root->right);
    }
    
    bool traverse(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
            return true;
        
        if(p == nullptr || q == nullptr)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return traverse(p->left, q->right) && traverse(p->right, q->left);
    }
};