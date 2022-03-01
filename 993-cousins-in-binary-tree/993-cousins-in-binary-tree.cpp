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
    bool isCousins(TreeNode* root, int x, int y) {
        int recorded = -1;
        bool isCousin = false;
        dfs(root, x, y, 0, recorded, isCousin);
        return isCousin;
    }
    
    bool dfs(TreeNode* root, int x, int y, int depth, int& recorded, bool& isCousin) {
        if(!root) return false;
        
        if(root->val == x || root->val == y) {
            if(recorded == -1) recorded = depth;
            return recorded == depth;
        }
        
        bool left = dfs(root->left, x, y, depth + 1, recorded, isCousin);
        bool right = dfs(root->right, x, y, depth + 1, recorded, isCousin);
        
        if(left && right && recorded != depth + 1)
            isCousin = true;
        
        return left || right;
    }
};