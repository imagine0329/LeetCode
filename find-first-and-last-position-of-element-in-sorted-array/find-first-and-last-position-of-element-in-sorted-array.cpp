class Solution {
public:
    int binarySearch_start(vector<int>& nums, int target, int left, int right)
    {
        int start = right;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {   
                start = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return start;
    }
    
    int binarySearch_end(vector<int>& nums, int target, int left, int right)
    {
        int end = left;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                end = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return end;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = 0, right = nums.size() - 1, mid;
        
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                ans[0] = binarySearch_start(nums, target, left, mid);
                ans[1] = binarySearch_end(nums, target, mid, right);
                break;
            }
            
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return ans;
    }
};