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
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        
        preorder(root, v);
        
        TreeNode* node = root;
        for(int i = 1; i < v.size(); i++) {
            node->left = nullptr;
            node->right = v[i];
            node = node->right;
        }
    }
    
    void preorder(TreeNode* root, vector<TreeNode*>& v) {
        if(root == nullptr)
            return;
        
        v.push_back(root);
        preorder(root->left, v);
        preorder(root->right, v);
    }
};