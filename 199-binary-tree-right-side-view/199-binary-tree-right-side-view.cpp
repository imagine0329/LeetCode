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
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int, vector<int>> m;
        
        dfs(root, m, 0);
        
        vector<int> ret;
        for(int i=0; i<m.size(); i++)
            ret.push_back(m[i].back());
        
        return ret;
    }
    
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& m, int level)
    {
        if(root == nullptr)
            return;
        
        m[level].push_back(root->val);
        dfs(root->left, m, level+1);
        dfs(root->right, m, level+1);
    }
};