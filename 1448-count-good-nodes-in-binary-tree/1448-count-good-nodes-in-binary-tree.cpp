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
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int count = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, INT_MIN});
        
        while(!s.empty()) {
            root = s.top().first;
            int maximum = s.top().second;
            s.pop();
            
            if(root->val >= maximum)
                count++;
            
            if(root->left)
                s.push({root->left, max(root->val, maximum)});
            if(root->right)
                s.push({root->right, max(root->val, maximum)});
        }
        
        return count;
    }
};