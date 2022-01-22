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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        dfs(root, 0, 0, m);
        
        vector<vector<int>> ans;
        for(auto c : m) {
            vector<int> v;
            for(auto r : c.second) {
                for(auto it = r.second.begin(); it != r.second.end(); ++it)
                    v.push_back(*it);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, int row, int col, map<int, map<int, multiset<int>>>& m) {
        if(!root) return;
        
        m[col][row].insert(root->val);
        dfs(root->left, row+1, col-1, m);
        dfs(root->right, row+1, col+1, m);
    }
};