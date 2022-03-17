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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recursive(root, ans, 0);
        return ans;
    }
    
    void recursive(TreeNode* root, vector<vector<int>>& ans, int level) {
        if(!root) return;
        if(ans.size() == level)
            ans.push_back({});
        
        ans[level].push_back(root->val);
        recursive(root->left, ans, level + 1);
        recursive(root->right, ans, level + 1);
    }
};