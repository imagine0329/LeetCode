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
        stack<TreeNode*> s1, s2;
        
        s1.push(p);
        s2.push(q);
        
        while(!s1.empty() && !s2.empty())
        {
            p = s1.top();
            s1.pop();
            q = s2.top();
            s2.pop();
            
            if(!p && !q)
                continue;
            
            if((p && !q) || (!p && q))
                return false;
            
            if(p->val != q->val)
                return false;
            
            s1.push(p->right);
            s2.push(q->right);
            s1.push(p->left);
            s2.push(q->left);
        }
        
        return s1.empty() && s2.empty();
    }
};