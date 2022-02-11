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
        deque<int> dq;
        return traverse(root, targetSum, dq, 0);
    }
    
    int traverse(TreeNode* root, int target, deque<int>& dq, int sum) {
        if(!root) return 0;
        
        int count = 0;
        sum += root->val;
        if(sum == target) count++;
        
        int tempSum = sum;
        deque<int>::iterator it = dq.begin();
        while(it != dq.end()) {
            tempSum -= *it++;
            if(tempSum == target) count++;
        }
        
        dq.push_back(root->val);
        count += traverse(root->left, target, dq, sum) + traverse(root->right, target, dq, sum);
        dq.pop_back();
        
        return count;
    }
};