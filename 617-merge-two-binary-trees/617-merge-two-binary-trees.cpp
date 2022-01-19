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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr)
            return root2;
        if(root2 == nullptr)
            return root1;
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});
        
        while(!q.empty()) {
            auto t1  = q.front().first;
            auto t2 = q.front().second;
            q.pop();
            
            if(!t1 || !t2)
                continue;
            
            t1->val += t2->val;
            
            if(!t1->left)
                t1->left = t2->left;
            else
                q.push({t1->left, t2->left});
            
            if(!t1->right)
                t1->right = t2->right;
            else
                q.push({t1->right, t2->right});
        }
        
        return root1;
    }
};