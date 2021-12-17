class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actual = accumulate(nums.begin(), nums.end(), 0);
        int expected = (n*(n+1))/2;
        
        return expected - actual;
    }
};