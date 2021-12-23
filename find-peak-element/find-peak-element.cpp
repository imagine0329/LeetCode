class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        int peak = INT_MIN;
        int peak_idx;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > peak)
            {
                peak = nums[i];
                peak_idx = i;
            }
        }
        
        return peak_idx;
    }
};