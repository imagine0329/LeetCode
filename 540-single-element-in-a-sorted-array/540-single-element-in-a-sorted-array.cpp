class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == nums[mid + 1]) {
                if(right - (mid + 1) & 1)
                    left = mid + 2;
                else
                    right = mid - 1;
            }
            else if(nums[mid] == nums[mid - 1]) {
                if(mid - 1 - left & 1)
                    right = mid - 2;
                else
                    left = mid + 1;
            }
            else
                return nums[mid];
        }
        
        return nums[left];
    }
};