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
        return inorder(root, nullptr, nullptr);
    }
    
    bool inorder(TreeNode* node, TreeNode* min, TreeNode* max)
    {
        if(node == nullptr)
            return true;
        
        if((max != nullptr && node->val >= max->val) || (min != nullptr && node->val <= min->val))
            return false;
        
        return inorder(node->left, min, node) && inorder(node->right, node, max);
    }
};

