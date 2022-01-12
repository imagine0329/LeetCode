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
private:
    priority_queue<int> q;
    
public:
    int kthSmallest(TreeNode* root, int k) {
        preorder(root, k);
        return q.top();
    }
    
    void preorder(TreeNode* root, int k)
    {
        if(root == nullptr)
            return;
        
        q.push(root->val);
        if(q.size() > k)
            q.pop();
        
        preorder(root->left, k);
        preorder(root->right, k);
    }
    
};