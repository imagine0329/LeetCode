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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        
        if(root->left || root->right)
            ans.push_back(root->val);
        
        TreeNode* node = root->left;
        while(node) {
            if(node->left || node->right)
                ans.push_back(node->val);
            
            if(node->left) node = node->left;
            else node = node->right;
        }
        
        addLeaves(root, ans);
        
        stack<TreeNode*> s;
        node = root->right;
        while(node) {
            if(node->left || node->right)
                s.push(node);
            
            if(node->right) node = node->right;
            else node = node->left;
        }
        
        while(!s.empty()) {
            ans.push_back(s.top()->val);
            s.pop();
        }
        
        return ans;
    }
    
    void addLeaves(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        
        if(!root->left && !root->right)
            ans.push_back(root->val);
        
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
};