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
        postorder(root, ans);
        
        return ans;
    }
    
    int postorder(TreeNode* root, vector<vector<int>>& ans) {
        if(root == nullptr)
            return 0;
        
        int left = postorder(root->left, ans);
        int right = postorder(root->right, ans);
        
        int idx = max(left, right);
        if(ans.size() == idx)
            ans.push_back({});
        
        ans[idx].push_back(root->val);
        return idx + 1;
    }
};