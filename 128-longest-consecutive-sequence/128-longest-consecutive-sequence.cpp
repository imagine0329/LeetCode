class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        int longest = 1;
        int length = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            
            if(nums[i] == nums[i-1] + 1)
                length++;
            else
            {
                longest = max(longest, length);
                length = 1;
            }
        }
        
        return max(longest, length);
    }
    
};