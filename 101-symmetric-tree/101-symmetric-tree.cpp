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
        if(root == nullptr)
            return true;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        queue<TreeNode*> l, r;
        l.push(left);
        r.push(right);
        
        while(!l.empty() && !r.empty())
        {
            left = l.front();
            l.pop();
            right = r.front();
            r.pop();
            
            if(!left && !right)
                continue;
            
            if(left == nullptr || right == nullptr)
                return false;
            if(left->val != right->val)
                return false;
            
            l.push(left->left);
            l.push(left->right);
            r.push(right->right);
            r.push(right->left);
        }
        
        return l.empty() && r.empty();
    }
};