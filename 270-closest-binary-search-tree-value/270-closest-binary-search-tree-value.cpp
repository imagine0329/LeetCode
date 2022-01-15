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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        stack<TreeNode*> s;
        
        s.push(root);
        
        while(!s.empty()) {
            root = s.top();
            s.pop();
            if(abs(target - root->val) < abs(target - closest))
                closest = root->val;
            
            if(root->left)
                s.push(root->left);
            if(root->right)
                s.push(root->right);
        }
        
        return closest;
    }
};