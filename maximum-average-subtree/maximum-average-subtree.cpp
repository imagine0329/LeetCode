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
        return maxAverage(root).maxAverage;
    }
    
private:
    struct State{
        int count;
        int sum;
        double maxAverage;
    };
    
    State maxAverage(TreeNode* root)
    {
        if(root == nullptr)
            return {0, 0, 0};
        
        State left = maxAverage(root->left);
        State right = maxAverage(root->right);
        
        int count = left.count + right.count + 1;
        int sum = left.sum + right.sum + root->val;
        double max_average = max((double)sum/count, max(left.maxAverage, right.maxAverage));
        
        return {count, sum, max_average};
    }
};