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
    int preorderIdx;
    unordered_map<int, int> inorderMap;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIdx = 0;
        for(int i=0; i<inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        return constructTree(preorder, 0, inorder.size() - 1);
    }
    
    TreeNode* constructTree(vector<int>& preorder, int left, int right)
    {
        if(left > right)
            return nullptr;
        
        int n = preorder[preorderIdx++];
        TreeNode* node = new TreeNode(n);
        
        node->left = constructTree(preorder, left, inorderMap[n] - 1);
        node->right = constructTree(preorder, inorderMap[n] + 1, right);
        
        return node;
    }
};