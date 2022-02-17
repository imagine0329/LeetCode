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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> v;
        inorder(root, v);
        
        root = v[0];
        TreeNode* node = root;
        for(int i = 1; i < v.size(); i++) {
            v[i]->left = nullptr;
            node->right = v[i];
            node = node->right;
        }
        
        return root;
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
};