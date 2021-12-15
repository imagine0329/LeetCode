class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;
        
        for(auto n : nums)
        {
            sum += n;
            if(sum < n)
                sum = n;
            
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
    }
};