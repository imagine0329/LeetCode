class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int closest = INT_MAX;
        int minSum = 0;
        for(int i=0; i<nums.size()-2; i++)
        {
            int sum = nums[i] + twoSumClosest(nums, target-nums[i], i+1);
            if(closest > abs(target - sum))
            {
                closest = abs(target - sum);
                minSum = sum;
            }
        }
        
        return minSum;
    }
    
    int twoSumClosest(vector<int>& nums, int target, int start)
    {
        int left = start, right = nums.size() - 1;
        int closest = INT_MAX;
        int minSum;
        
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            
            if(closest > abs(target - sum))
            {
                closest = abs(target - sum);
                minSum = sum;
            }
            
            if(sum < target)
                left++;
            else
                right--;
        }
        
        return minSum;
    }
};