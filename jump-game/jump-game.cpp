class Solution {
private:
    vector<int> memo;
    
public:
    bool canJump(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        
        memo[nums.size()-1] = 1;
        int ret = jump(nums, 0);
        
        return ret == 1 ? true : false;
    }
    
    int jump(vector<int>& nums, int position)
    {
        if(memo[position] != -1)
            return memo[position];
        
        int x = nums.size() - 1;
        int n = min(position + nums[position], x);
        int result = 0;
        for(int i=n; i>position; i--)
        {
            result = jump(nums, i);
            if(result == 1)
                break;
        }
        
        memo[position] = result;
        return memo[position];
    }
};