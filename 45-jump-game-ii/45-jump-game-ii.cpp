class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 10001);
        
        
        
        return helper(nums, 0, dp);
    }
    
    int helper(vector<int>& nums, int start, vector<int>& dp) {
        if(start >= nums.size() - 1) return 0;
        if(dp[start] < 10001) return dp[start];
        
        for(int i = nums[start]; i > 0; i--)
            dp[start] = min(dp[start], helper(nums, start + i, dp) + 1);
        
        return dp[start];
    }
};