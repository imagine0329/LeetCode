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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        
        int left = 0, right = v.size() - 1;
        while(left < right) {
            int val = v[left] + v[right];
            if(val == k)
                return true;
            
            if(val < k)
                left++;
            else
                right--;
        }
        
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& v) {
        if(root == nullptr)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};