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
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        map<int, vector<pair<int, int>>> m;
        
        dfs(root, 0, 0, m);
        for(auto& n : m) {
            vector<int> v;
            sort(n.second.begin(), n.second.end(), compare);
            for(auto& s : n.second) {
                v.push_back(s.second);
            }
            ret.push_back(v);
        }
        
        return ret;
    }
    
    void dfs(TreeNode* root, int col, int row, map<int, vector<pair<int, int>>>& m) {
        if(root == nullptr)
            return;
        
        m[col].push_back({row, root->val});
        dfs(root->left, col - 1, row + 1, m);
        dfs(root->right, col + 1, row + 1, m);
    }
};