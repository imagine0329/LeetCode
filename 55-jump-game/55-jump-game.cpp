class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        
        dp[n-1] = true;
        for(int i=n-2; i>=0; i--)
        {
            int furthest = min(nums[i]+i, n-1);
            for(int k=furthest; k>i; k--)
            {
                if(dp[k])
                {
                    dp[i] = dp[k];
                    break;
                }
            }
        }
        
        return dp[0];
    }
};