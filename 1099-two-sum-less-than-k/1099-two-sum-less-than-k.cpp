class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        vector<int> count(1001, 0);
        for(auto n : nums)
            count[n]++;
        
        int maxSum = -1;
        int lo = 1, hi = 1000;
        while(lo <= hi) {
            if(lo + hi >= k || count[hi] == 0)
                hi--;
            else {
                if(count[lo] > (lo < hi ? 0 : 1))
                    maxSum = max(maxSum, lo + hi);
                lo++;
            }
        }
        
        return maxSum;
    }
};