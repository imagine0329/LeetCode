/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    TreeNode* target;
    int k;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->target = target;
        this->k = k;
        
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode* root) {
        if(!root) return -1;
        else if(root == target) {
            subtree_add(root, 0);
            return 1;
        }
        else {
            int left = dfs(root->left), right = dfs(root->right);
            if(left != -1) {
                if(left == k) ans.push_back(root->val);
                else subtree_add(root->right, left + 1);
                return left + 1;
            }
            else if(right != -1) {
                if(right == k) ans.push_back(root->val);
                else subtree_add(root->left, right + 1);
                return right + 1;
            }
            else return -1;
        }
    }
    
    void subtree_add(TreeNode* root, int dist) {
        if(!root) return;
        if(dist == k) ans.push_back(root->val);
        else {
            subtree_add(root->left, dist + 1);
            subtree_add(root->right, dist + 1);
        }
    }
};