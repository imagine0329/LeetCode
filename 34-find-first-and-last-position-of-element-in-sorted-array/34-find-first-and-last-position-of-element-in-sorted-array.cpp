class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size() < 1)
            return ans;
            
        int left = 0, right = nums.size()-1;
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        
        if(nums[left] != target)
            return ans;
        
        ans[0] = left;
        
        right = nums.size()-1;
        while(left < right)
        {
            int mid = left + (right-left)/2 + 1;
            if(nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        
        ans[1] = left;
        
        return ans;
    }
};