class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int maximum = -1;
        vector<int> count(1001, 0);
        
        for(auto n : nums)
            count[n]++;
        
        int lo = 1, hi = 1000;
        while(lo <= hi) {
            if(lo + hi >= k || count[hi] == 0)
                hi--;
            else {
                if(count[lo] > (lo < hi ? 0 : 1))
                    maximum = max(maximum, lo + hi);
                lo++;
            }
        }
        
        return maximum;
    }
};