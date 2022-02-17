class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maximum = -1;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] < k; i++) {
            int j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) - nums.begin() - 1;
            if(j != i)
                maximum = max(maximum, nums[i] + nums[j]);
        }
        
        return maximum;
    }
};