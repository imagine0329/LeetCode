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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node = root;
        
        while(node)
        {
            if(node->left)
            {
                TreeNode* rightmost = node->left;
                while(rightmost->right)
                    rightmost = rightmost->right;
                
                rightmost->right = node;
                TreeNode* temp = node->left;
                node->left = nullptr;
                node = temp;
            }
            else
            {
                ans.push_back(node->val);
                node = node->right;
            }
        }
        
        return ans;
    }
    
};