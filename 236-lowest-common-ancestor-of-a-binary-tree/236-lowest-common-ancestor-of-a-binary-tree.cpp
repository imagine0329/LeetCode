/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        
        unordered_map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> s;
        
        parent[root] = nullptr;
        s.push(root);
        
        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            root = s.top(); s.pop();
            if(root->left) {
                s.push(root->left);
                parent[root->left] = root;
            }
            if(root->right) {
                s.push(root->right);
                parent[root->right] = root;
            }
        }
        
        unordered_set<TreeNode*> seen;
        while(p) {
            seen.insert(p);
            p = parent[p];
        }
        
        while(seen.find(q) == seen.end())
            q = parent[q];
        
        return q;
    }
};