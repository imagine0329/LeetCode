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
    int max_depth = 0;
    
    int next_maxDepth()
    {
        if(q.empty())
            return max_depth;
        
        auto next = q.front();
        q.pop();
        
        auto node = next.first;
        auto level = next.second + 1;
        
        max_depth = max(max_depth, level);
        
        if(node->left)
            q.push(make_pair(node->left, level));
        if(node->right)
            q.push(make_pair(node->right, level));
        
        return next_maxDepth();
    }
    
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        q.push(make_pair(root, 0));
        
        return next_maxDepth();
    }
};