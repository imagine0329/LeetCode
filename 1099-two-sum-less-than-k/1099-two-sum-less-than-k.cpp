class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maximum = -1;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] < k; i++) {
            int j = binarySearch(nums, k - nums[i], i + 1) - 1;
            if(j > i)
                maximum = max(maximum, nums[i] + nums[j]);
        }
        
        return maximum;
    }
    
    int binarySearch(vector<int>& nums, int k, int start) {
        int left = start, right = nums.size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < k)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};