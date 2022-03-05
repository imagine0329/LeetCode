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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> s(nodes.begin(), nodes.end());
        return LCA(root, s);
    }
    
    TreeNode* LCA(TreeNode* root, unordered_set<TreeNode*>& s) {
        if(!root) return nullptr;
        if(s.find(root) != s.end()) return root;
        
        TreeNode* left = LCA(root->left, s);
        TreeNode* right = LCA(root->right, s);
        
        if(left && right) return root;
        else return left ? left : right;
    }
};