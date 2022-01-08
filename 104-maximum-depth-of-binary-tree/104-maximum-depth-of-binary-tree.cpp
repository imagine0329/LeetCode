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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int max_depth = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        
        while(!q.empty())
        {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();
            
            max_depth = max(max_depth, level);
            
            if(node->left)
                q.push(make_pair(node->left, level+1));
            if(node->right)
                q.push(make_pair(node->right, level+1));
        }
        
        return max_depth;
    }
};