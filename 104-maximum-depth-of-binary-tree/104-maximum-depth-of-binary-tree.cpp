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
    queue<pair<TreeNode*, int>> q;
    int max_depth;
    
    int next()
    {
        if(q.size() == 0)
            return max_depth;
        
        auto node = q.front().first;
        auto level = q.front().second + 1;
        q.pop();
        
        max_depth = max(max_depth, level);
        
        if(node->left)
            q.push(make_pair(node->left, level));
        if(node->right)
            q.push(make_pair(node->right, level));
        
        return next();
    }
    
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        max_depth = 0;
        q.push(make_pair(root, 0));
        
        return next();
    }
};