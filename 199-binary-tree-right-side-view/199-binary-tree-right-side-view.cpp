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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(root && !q.empty())
        {
            int n = q.size();
            while(n--)
            {
                root = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            
            ans.push_back(root->val);
        }
        
        return ans;
    }
};