/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*  1st Approach*/
class Solution {
private:
    vector<TreeNode*> v;
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root);
        for(vector<TreeNode*>::iterator it = v.begin(); it!=v.end(); it++)
        {
            if((*it) == p)
            {
                if(++it == v.end())
                    return nullptr;
                
                return *(it);
            }    
        }
        
        return nullptr;
    }
    
    void inorder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
};