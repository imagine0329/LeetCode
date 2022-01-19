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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()) {
            root = q.front();
            q.pop();
            
            if(s.find(k - root->val) != s.end())
                return true;
            s.insert(root->val);
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        
        return false;
    }
};