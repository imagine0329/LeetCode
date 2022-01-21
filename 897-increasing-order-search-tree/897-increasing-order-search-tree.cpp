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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        TreeNode* prev = head;
        stack<TreeNode*> s;
        
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            prev->right = root;
            prev = root;
            root->left = nullptr;
            root = root->right;
        }
        
        return head->right;
    }
};