class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    int helper(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return INT_MIN;
        
        int mid = left + (right - left)/2;
        int bestLeft = 0, bestRight = 0, sum = 0;
        
        for(int i=mid-1; i>=left; i--)
        {
            sum += nums[i];
            bestLeft = max(sum, bestLeft);
        }
        
        sum = 0;
        for(int i=mid+1; i<=right; i++)
        {
            sum += nums[i];
            bestRight = max(sum, bestRight);
        }
        
        int combined = bestLeft + bestRight + nums[mid];
        
        int leftHalf = helper(nums, left, mid-1);
        int rightHalf = helper(nums, mid+1, right);
        
        return max(combined, max(leftHalf, rightHalf));
    }
    
};