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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return traverse(root, k, s);
    }
    
    bool traverse(TreeNode* root, int k, unordered_set<int>& s) {
        if(root == nullptr)
            return false;
        
        if(s.find(k - root->val) != s.end())
            return true;
        
        s.insert(root->val);
        return traverse(root->left, k, s) || traverse(root->right, k, s);
    }
};