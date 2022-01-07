class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        
        for(int left=0; left<nums.size()-1; left++)
        {
            for(int right = left+1; right<nums.size(); right++)
            {
                if(nums[left] > nums[right])
                    swap(nums[left], nums[right]);
            }
        }
    }
};