class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left + 1) / 2;
            int missing = nums[mid] - nums[left] - (mid - left);
            if(missing < k) {
                left = mid;
                k -= missing;
            }
            else
                right = mid - 1;
        }
        
        return nums[left] + k;
    }
};