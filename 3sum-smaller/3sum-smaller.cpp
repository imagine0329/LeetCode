class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int i=0; i<nums.size()-2; i++)
            count += twoSumSmaller(nums, i+1, target - nums[i]);
        
        return count;
    }
    
    int twoSumSmaller(vector<int>& nums, int startIndex, int target)
    {
        int count = 0;
        int left = startIndex;
        int right = nums.size()-1;
        
        while(left < right)
        {
            if(nums[left] + nums[right] < target)
            {
                count += right - left;
                left++;
            }
            else
                right--;
        }
        
        return count;
    }
};