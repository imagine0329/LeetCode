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
        
        traverse(root, ans, 0);
        
        return ans;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>& ans, int level)
    {
        if(root == nullptr)
            return;
        
        if(ans.size() == level)
            ans.push_back({});
        
        if(level & 1)
        {
            auto it = ans[level].begin();
            ans[level].insert(it, root->val);
        }
        else
            ans[level].push_back(root->val);
        
        traverse(root->left, ans, level+1);
        traverse(root->right, ans, level+1);
    }
};