class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maximum = INT_MIN;
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            if(nums[left] + nums[right] >= k)
                right--;
            else {
                maximum = max(maximum, nums[left] + nums[right]);
                left++;
            }
        }
        
        return maximum == INT_MIN ? -1 : maximum;
    }
};