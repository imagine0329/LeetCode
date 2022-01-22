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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            root = s.top();
            s.pop();
            if(root->val >= low && root->val <= high)
                sum += root->val;
            if(root->left && root->val > low)
                s.push(root->left);
            if(root->right && root->val < high)
                s.push(root->right);
        }
        
        return sum;
    }
};