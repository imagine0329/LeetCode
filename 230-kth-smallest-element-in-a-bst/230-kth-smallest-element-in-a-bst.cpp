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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
            return -1;
        
        vector<int> v;
        stack<TreeNode*> s;
        
        while(root || !s.empty())
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        
        return v[k-1];
    }
};