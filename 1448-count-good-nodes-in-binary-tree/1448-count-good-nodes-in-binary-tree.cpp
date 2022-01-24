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
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int count = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        
        while(!q.empty()) {
            root = q.front().first;
            int maximum = q.front().second;
            q.pop();
            
            if(root->val >= maximum)
                count++;
            
            if(root->left)
                q.push({root->left, max(root->val, maximum)});
            if(root->right)
                q.push({root->right, max(root->val, maximum)});
        }
        
        return count;
    }
};