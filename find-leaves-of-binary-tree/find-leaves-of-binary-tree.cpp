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
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->ans.clear();
        getHeight(root);
        return ans;
    }
    
    int getHeight(TreeNode* root)
    {
        if(root == nullptr)
            return -1;
        
        int l_height = getHeight(root->left);
        int r_height = getHeight(root->right);
        int cur_height = max(l_height, r_height) + 1;
        
        if(ans.size() == cur_height)
            ans.push_back({});
        
        ans[cur_height].push_back(root->val);
        
        return cur_height;
    }
};