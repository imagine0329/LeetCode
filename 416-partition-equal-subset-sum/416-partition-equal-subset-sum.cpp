class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(auto n : nums)
            sum += n;
        if(sum & 1) return false;
        
        vector<vector<optional<bool>>> dp(n, vector<optional<bool>>(sum + 1, nullopt));
        return recursive(nums, dp, 0, sum / 2);
    }
    
    bool recursive(vector<int>& nums, vector<vector<optional<bool>>>& dp, int i, int remain) {
        if(remain == 0) return true;
        if(i == nums.size() || remain < 0) return false;
        if(dp[i][remain] != nullopt)
            return dp[i][remain].value();
        
        bool res = recursive(nums, dp, i + 1, remain - nums[i]) || recursive(nums, dp, i + 1, remain);
        dp[i][remain] = res;
        return res;
    }
};