class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        for(int start = nums.size() - 2; start >= 1; start--) {
            for(int end = start; end <= nums.size() - 2; end++) {
                for(int i = start; i <= end; i++) {
                    int gain = nums[start - 1] * nums[i] * nums[end + 1];
                    int remain = dp[start][i - 1] + dp[i + 1][end];
                    dp[start][end] = max(remain + gain, dp[start][end]);
                }
            }
        }
        
        return dp[1][nums.size() - 2];
    }
};