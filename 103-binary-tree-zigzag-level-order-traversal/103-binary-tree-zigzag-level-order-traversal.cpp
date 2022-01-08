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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        bool isZig = true;
        
        dq.push_back(root);
        
        while(!dq.empty()) {
            vector<int> level;
            int size = dq.size();
            while(size--)
            {
                if(isZig)
                {
                    root = dq.back();
                    dq.pop_back();
                    level.push_back(root->val);
                    if(root->left)  dq.push_front(root->left);
                    if(root->right) dq.push_front(root->right);
                }
                else
                {
                    root = dq.front();
                    dq.pop_front();
                    level.push_back(root->val);
                    if(root->right) dq.push_back(root->right);
                    if(root->left)  dq.push_back(root->left);
                }
            }
            
            ans.push_back(level);
            isZig = !isZig;
        }
        
        return ans;
    }
    
};