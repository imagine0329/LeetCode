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
    
    bool inorder(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        if(root == nullptr)
            return true;
        
        bool left = inorder(root->left, lower, root);
        
        if(lower && root->val <= lower->val)
            return false;
        if(upper && root->val >= upper->val)
            return false;
        
        bool right = inorder(root->right, root, upper);
        
        return left && right;
    }
};

