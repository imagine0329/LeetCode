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
        stack<TreeNode*> s;
        TreeNode* prev = nullptr;
        
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            TreeNode* curr = s.top(); s.pop();
            if(prev && prev->val >= curr->val)
                return false;
            
            root = curr->right;
            prev = curr;
        }
        
        return true;
    }
};