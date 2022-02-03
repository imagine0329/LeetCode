class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while(left < right) {
            int mid = (left + right) >> 1;
            if(nums[right] < nums[mid])
                left = mid + 1;
            else if(nums[right] > nums[mid])
                right = mid;
            else
                right--;
        }
        
        return nums[left];
    }
};