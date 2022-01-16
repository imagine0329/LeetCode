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
    int longestConsecutive(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int longest = 0;
        
        q.push({root, 1});
        while(!q.empty() && root) {
            int n = q.size();
            
            while(n--) {
                root = q.front().first;
                int len = q.front().second;
                q.pop();
                longest = max(longest, len);
                
                if(root->left) {
                    if(root->left->val == root->val + 1)
                        q.push({root->left, len + 1});
                    else
                        q.push({root->left, 1});
                }
                
                if(root->right) {
                    if(root->right->val == root->val + 1)
                        q.push({root->right, len + 1});
                    else
                        q.push({root->right, 1});
                }
            }
        }
        
        return longest;
    }
};