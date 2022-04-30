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
    unordered_map<string, int> m;
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        
        traverse(root, ans);
        return ans;
    }
    
    string traverse(TreeNode* root, vector<TreeNode*>& ans) {
        if(!root)
            return "";
        
        string s = to_string(root->val) + "," + traverse(root->left, ans) + "," + traverse(root->right, ans);
        if(++m[s] == 2)
            ans.push_back(root);
        
        return s;
    }
};

/*
            1
        2       3
    4         2
            4
  
key     val
value   node
1       <1>
2       <2>
4       <4>
3       <3>

found same a node with same value
    from node1 and node2
    check if they are identical tree
        if not same
            return false
        else
            return true
*/