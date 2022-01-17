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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty() && root) {
            int n = q.size();
            while(n--) {
                root = q.front().first;
                int col = q.front().second;
                q.pop();
                
                m[col].push_back(root->val);
                
                if(root->left)
                    q.push({root->left, col - 1});
                if(root->right)
                    q.push({root->right, col + 1});
            }
        }
        
        vector<vector<int>> ret;
        for(auto n : m)
            ret.push_back(n.second);
        
        return ret;
    }
};