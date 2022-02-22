class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, -1));
        vector<int> arr;
        arr.push_back(1);
        for(auto n : nums)
            arr.push_back(n);
        arr.push_back(1);
        
        return helper(arr, 1, arr.size() - 2, dp);
    }
    
    int helper(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if(start > end) return 0;
        if(start == end) {
            int temp = nums[start];
            if(start - 1 >= 0) temp *= nums[start - 1];
            if(start + 1 < nums.size()) temp *= nums[start + 1];
        }
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = 0;
        for(int k = start; k <= end; k++) {
            int temp = nums[k];
            if(start - 1 >= 0) temp *= nums[start - 1];
            if(end + 1 < nums.size()) temp *= nums[end + 1];
            temp += helper(nums, start, k - 1, dp) + helper(nums, k + 1, end, dp);
            ans = max(ans, temp);
        }
        
        return dp[start][end] = ans;
    }
};