class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        int left = 1;
        int right = 1;
        
        while(right < nums.size())
        {
            if(nums[right-1] == nums[right])
            {
                right++;
                continue;
            }
            
            nums[left++] = nums[right++];
        }
        
        return left;
    }
};