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
            TreeNode* node = s.top();
            s.pop();
            
            if(node->left) {
                s.push(node->left);
                parent[node->left] = node;
            }
            if(node->right) {
                s.push(node->right);
                parent[node->right] = node;
            }
        }
        
        unordered_set<TreeNode*> ancestor;
        while(p) {
            ancestor.insert(p);
            p = parent[p];
        }
        
        while(ancestor.find(q) == ancestor.end())
            q = parent[q];
        
        return q;
    }
};