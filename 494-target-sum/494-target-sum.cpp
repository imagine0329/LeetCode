class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(auto n : nums)
            total += n;
        
        vector<vector<int>> dp(2 * total + 1, vector<int>(nums.size(), -1));
        return backtracking(nums, target, total, 0, 0, dp);
    }
    
    int backtracking(vector<int>& nums, int target, int total, int i, int sum, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            if(sum == target) return 1;
            else return 0;
        }
        
        if(dp[sum + total][i] != -1) return dp[sum + total][i];

        int count = backtracking(nums, target, total, i + 1, sum + nums[i], dp)
                + backtracking(nums, target, total, i + 1, sum - nums[i], dp);
        
        dp[sum + total][i] = count;
        return count;
    }
};