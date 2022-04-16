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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        
        return ans;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& ans, int level) {
        if(!root)
            return;
        
        if(ans.size() == level)
            ans.push_back({});
        
        if(level % 2 == 0) {
            ans[level].push_back(root->val);
        }
        else {
            ans[level].insert(ans[level].begin(), root->val);
        }
        
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
};

/*
        1               level = 0(even): left->right
    2       3           level = 1(odd): right->left; reversed order
4     5   6     7

*/