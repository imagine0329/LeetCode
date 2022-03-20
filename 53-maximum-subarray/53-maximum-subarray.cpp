class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN;
        
        int sum = 0;
        for(auto n : nums) {
            sum += n;
            if(sum < n)
                sum = n;
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};