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
    bool isSymmetric(TreeNode* root) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({root->left, root->right});
        
        while(!s.empty()) {
            auto l = s.top().first, r = s.top().second;
            s.pop();
            
            if(!l && !r) continue;
            if(!l || !r) return false;
            if(l->val != r->val) return false;
            s.push({l->left, r->right});
            s.push({l->right, r->left});
        }
        
        return true;
    }
};