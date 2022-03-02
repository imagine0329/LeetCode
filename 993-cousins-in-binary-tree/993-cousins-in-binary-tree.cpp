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
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sibling = false, cousin = false;
            int n = q.size();
            while(n--) {
                root = q.front(); q.pop();
                if(!root) sibling = false;
                else {
                    if (root->val == x || root->val == y) {
                        if(!cousin) sibling = cousin = true;
                        else return !sibling;
                    }
                    if(root->left) q.push(root->left);
                    if(root->right) q.push(root->right);
                    q.push(nullptr);
                }
            }
            if(cousin) return false;
        }
        return false;
    }
};