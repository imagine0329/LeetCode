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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        
        q1.push(p);
        q2.push(q);
        
        while(!q1.empty() && !q2.empty())
        {
            p = q1.front();
            q1.pop();
            q = q2.front();
            q2.pop();
            
            if(!p && !q)
                continue;
            
            if(p == nullptr || q == nullptr)
                return false;
            if(p->val != q->val)
                return false;
            
            q1.push(p->left);
            q2.push(q->left);
            q1.push(p->right);
            q2.push(q->right);
        }
        
        return q1.empty() && q2.empty();
    }
};