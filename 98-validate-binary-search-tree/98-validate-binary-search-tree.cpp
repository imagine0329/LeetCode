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
        return traverse(root, nullptr, nullptr);
    }
    
    bool traverse(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if(root == nullptr)
            return true;
        
        if((min && root->val <= min->val) || (max && root->val >= max->val))
            return false;
        
        return traverse(root->left, min, root) && traverse(root->right, root, max);
    }
};

