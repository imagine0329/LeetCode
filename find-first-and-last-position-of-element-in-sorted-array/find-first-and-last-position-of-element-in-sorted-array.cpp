class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(start == nums.size() || nums[start] != target)
            return {-1, -1};
        
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        return {start, end};
    }
};