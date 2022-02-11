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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> prefix;
        return traverse(root, targetSum, prefix, 0);
    }
    
    int traverse(TreeNode* root, int target, unordered_map<int, int>& prefix, int sum) {
        if(!root) return 0;
        
        int count = 0;
        sum += root->val;
        if(sum == target) count++;
        count += prefix[sum - target];
        
        prefix[sum]++;
        count += traverse(root->left, target, prefix, sum) + traverse(root->right, target, prefix, sum);
        prefix[sum]--;
        
        return count;
    }
};