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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<TreeNode*> q;
        TreeNode* node = root;
        q.push(node);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                node = q.front();
                q.pop();
                
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        return root;
    }
};