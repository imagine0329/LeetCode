class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int triplet = 0;
        for(int i=0; i<n-2; i++)
            triplet += twoSum(nums, target-nums[i], i+1);
        
        return triplet;
    }
    
    int twoSum(vector<int>& nums, int target, int start) {
        int left = start, right = nums.size()-1;
        int num = 0;
        while(left < right) {
            if(target - nums[left] - nums[right] > 0) {
                num += right - left;
                left++;
            }
            else
                right--;
        }
        
        return num;
    }
    
};