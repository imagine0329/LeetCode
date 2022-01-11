class Solution {
private:
    vector<int> memo;
    
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];
        
        memo = vector<int>(nums.size(), -1);
        return dp(nums, 0);
    }
    
    int dp(vector<int>& nums, int i)
    {
        if(i >= nums.size())
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        return memo[i] = max(dp(nums, i+1), dp(nums, i+2) + nums[i]);
    }
};