class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int maxSum = -1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum < k) {
                maxSum = max(maxSum, sum);
                left++;
            }
            else right--;
        }
        
        return maxSum;
    }
};