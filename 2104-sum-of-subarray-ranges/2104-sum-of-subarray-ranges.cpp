class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            int minimum = nums[i], maximum = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                minimum = min(minimum, nums[j]);
                maximum = max(maximum, nums[j]);
                sum += maximum - minimum;
            }
        }
        
        return sum;
    }
};