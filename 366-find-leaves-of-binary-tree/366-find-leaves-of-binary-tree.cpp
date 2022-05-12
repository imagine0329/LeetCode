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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& ans) {
        if(!root)
            return -1;
        
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        int level = max(left, right) + 1;
        
        if(ans.size() == level)
            ans.push_back({});
        
        ans[level].push_back(root->val);
        return level;
    }
};

/*
        1(2)
    2(1)       3(0)
 4(0)  5(0)
*/