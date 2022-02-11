class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtracking(nums, target, 0, 0);
    }
    
    int backtracking(vector<int>& nums, int target, int i, int sum) {
        if(i == nums.size()) {
            if(sum == target) return 1;
            else return 0;
        }

        return backtracking(nums, target, i + 1, sum + nums[i])
                + backtracking(nums, target, i + 1, sum - nums[i]);
    }
};