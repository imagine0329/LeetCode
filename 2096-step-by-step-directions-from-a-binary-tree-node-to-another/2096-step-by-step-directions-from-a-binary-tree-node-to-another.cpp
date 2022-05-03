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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        
        string pathToStart, pathToDest;
        findNode(root, startValue, pathToStart);
        findNode(root, destValue, pathToDest);
        
        for(auto& c : pathToStart)
            c = 'U';
        
        return pathToStart + pathToDest;
    }
    
    TreeNode* lca(TreeNode* root, int start, int dest) {
        if(!root)
            return nullptr;
        
        if(root->val == start || root->val == dest)
            return root;
        
        TreeNode* left = lca(root->left, start, dest);
        TreeNode* right = lca(root->right, start, dest);
        if(left && right)
            return root;
        
        return left ? left : right;
    }
    
    bool findNode(TreeNode* root, int node, string& str) {
        if(!root)
            return false;
        if(root->val == node)
            return true;
        
        str.push_back('L');
        if(findNode(root->left, node, str))
            return true;
        str.pop_back();
        
        str.push_back('R');
        if(findNode(root->right, node, str))
            return true;
        str.pop_back();
        
        return false;
    }
};
/*
        5
    1          2(d)(lca)
3          6         4
         7   8(s)


to s : R->L->R
to d : R
UU

        5(lca)
    1          2
3(s)       6         4
         7   8(d)
            
to s : L->L
to d : R->L->R
UU RLR

        5
    1          2(lca)
3          6         4(s)
         7   8(d)
            
to s : R->R
to d : R->L->R
U LR
*/