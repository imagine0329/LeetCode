/*  One Pass*/
class Solution {
public:
    int missing(vector<int>& nums, int idx)
    {
        return nums[idx] - nums[0] - idx;
    }
    
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k > missing(nums, n-1))
            return nums[n-1] + (k - missing(nums, n-1));
        
        int idx = 1;
        while(k > missing(nums, idx))
            idx++;
        
        return nums[idx-1] + (k - missing(nums, idx-1));
    }
};