class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        
        int sum = 0;
        for(auto n : nums)
        {
            sum += n;
            sum = max(sum, n);
            maxSum = max(sum, maxSum);
        }
        
        return maxSum;
    }
    
};