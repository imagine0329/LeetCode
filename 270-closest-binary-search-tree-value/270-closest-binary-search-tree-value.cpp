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
    int closestValue(TreeNode* root, double target) {
        int curr = root->val;
        int sub = root->val;
        
        if(target < root->val && root->left)
            sub = closestValue(root->left, target);
        else if(target > root->val && root->right)
            sub = closestValue(root->right, target);
        
        if(abs(curr - target) < abs(sub - target))
            return curr;
        else
            return sub;
    }
};