class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n-2; i++)
        {
            int left = i+1, right = n-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target-sum) < abs(diff))
                    diff = target - sum;
                
                if(sum <= target)
                    left++;
                else
                    right--;
            }
        }
        
        return target - diff;
    }
};