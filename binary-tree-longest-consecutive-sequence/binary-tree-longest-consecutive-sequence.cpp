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
    int max_path;
public:
    int longestConsecutive(TreeNode* root) {
        return dfs(root, nullptr, 0);
    }
    
    int dfs(TreeNode* root, TreeNode* parent, int length)
    {
        if(root == nullptr)
            return length;
        
        length = (parent != nullptr && root->val == parent->val + 1) ?
            length + 1 : 1;
        
        return max(length, max(dfs(root->left, root, length), 
                              dfs(root->right, root, length)));
    }
    
};