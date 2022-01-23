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
    double maximumAverageSubtree(TreeNode* root) {
        double maxAverage = 0;
        traverse(root, maxAverage);
        return maxAverage;
    }
    
    pair<int, int> traverse(TreeNode* root, double& maxAverage) {
        if(root == nullptr)
            return {0 ,0};
        
        auto left = traverse(root->left, maxAverage);
        auto right = traverse(root->right, maxAverage);
        
        int count = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;
        maxAverage = max(maxAverage, (double)sum / count);
        
        return {count, sum};
    }
};