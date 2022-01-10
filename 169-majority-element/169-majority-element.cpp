class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 0;
        int len = 1, idx = 0;
        while(right < nums.size())
        {
            if(nums[left] != nums[right])
                left = right;
            
            if(len < right - left + 1)
            {
                len = right - left;
                idx = left;
            }
            
            right++;
        }
        
        return nums[idx];
    }
};