class Solution {
private:
    vector<int> memo;
    
public:
    bool canJump(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        
        memo[nums.size()-1] = 1;
        jump(nums, 0);
        
        return memo[0] == 1 ? true : false;
    }
    
    int jump(vector<int>& nums, int i)
    {
        if(memo[i] != -1)
            return memo[i];
        
        int n = nums.size();
        int furthest = min(nums[i] + i, n-1);
        for(int k=furthest; k>i; k--)
        {
            if(jump(nums, k) == 1)
            {
                memo[i] = true;
                return memo[i];
            }
        }
        
        memo[i] = 0;
        return memo[i];
    }
    
};