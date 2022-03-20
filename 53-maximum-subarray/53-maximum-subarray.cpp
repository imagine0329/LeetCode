class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return findBestSubarray(nums, 0, nums.size() - 1);
    }
    
    int findBestSubarray(vector<int>& nums, int left, int right) {
        if(left > right) return INT_MIN;
        
        int mid = left + (right - left) / 2;
        int sum = 0, lSum = 0, rSum = 0;
        
        for(int i = mid - 1; i >= left; i--) {
            sum += nums[i];
            lSum = max(lSum, sum);
        }
        sum = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rSum = max(rSum, sum);
        }
        
        int bestSum = nums[mid] + lSum + rSum;
        int leftHalf = findBestSubarray(nums, left, mid - 1);
        int rightHalf = findBestSubarray(nums, mid + 1, right);
        return max(bestSum, max(leftHalf, rightHalf));
    }
};