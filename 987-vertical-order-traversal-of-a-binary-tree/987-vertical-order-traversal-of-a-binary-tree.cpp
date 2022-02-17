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
        
        dfs(root, m, 0, 0);
        
        vector<vector<int>> ans(m.size());
        int i = 0;
        for(auto col : m) {
            for(auto row : col.second) {
                for(auto val : row.second)
                    ans[i].push_back(val);
            }
            i++;
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, map<int, map<int, multiset<int>>>& m, int row, int col) {
        if(!root) return;
        
        m[col][row].insert(root->val);
        dfs(root->left, m, row + 1, col - 1);
        dfs(root->right, m, row + 1, col + 1);
    }
};