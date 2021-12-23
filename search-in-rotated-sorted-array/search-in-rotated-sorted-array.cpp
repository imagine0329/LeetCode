class Solution {
public:
    /*
    Formula: If a sorted array is shifted, if you take the middle, always one side will be sorted. Take the recursion           according to that rule.

    1- take the middle and compare with target, if matches return.
    2- if middle is bigger than left side, it means left is sorted
        2a- if [left] < target < [middle] then do recursion with left, middle - 1 (right)
        2b- left side is sorted, but target not in here, search on right side middle + 1 (left), right
    3- if middle is less than right side, it means right is sorted
        3a- if [middle] < target < [right] then do recursion with middle + 1 (left), right
        3b- right side is sorted, but target not in here, search on left side left, middle -1 (right)
    */
    
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        
        if(nums[pivot] == target)
            return pivot;
        
        if(pivot == 0)
            return findTarget(nums, target, 0, nums.size() - 1);
        
        if(target < nums[0])
            return findTarget(nums, target, pivot, nums.size() - 1);
        else
            return findTarget(nums, target, 0, pivot - 1);
    }
    
    int findPivot(vector<int>& nums)
    {
        if(nums.front() < nums.back())
            return 0;
        
        int left = 0, right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= nums[0])
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
    
    int findTarget(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    
};