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
    stack<TreeNode*> s, lower_limit, upper_limit;
    
    void update(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        s.push(root);
        lower_limit.push(lower);
        upper_limit.push(upper);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *lower = nullptr, *upper = nullptr;
        
        while(root || !s.empty())
        {
            while(root)
            {
                update(root, lower, upper);
                upper = root;
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            lower = lower_limit.top();
            lower_limit.pop();
            upper = upper_limit.top();
            upper_limit.pop();
            
            if(lower && root->val <= lower->val)
                return false;
            if(upper && root->val >= upper->val)
                return false;
            
            lower = root;
            root = root->right;
        }
        
        return true;
    }
};

