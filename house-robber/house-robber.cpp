class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return robFrom(memo, nums, 0);
    }
    
    int robFrom(vector<int>& memo, vector<int>& nums, int i){
        if(i >= nums.size())
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int ans = max(robFrom(memo, nums, i+1), robFrom(memo, nums, i+2)+nums[i]);
        memo[i] = ans;
        
        return ans;
    }
};