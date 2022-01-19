class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3, min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        
        for(auto n : nums) {
            if(min1 > n) {
                min2 = min1;
                min1 = n;
            }
            else if(min2 > n)
                min2 = n;
            
            if(max1 < n) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if(max2 < n) {
                max3 = max2;
                max2 = n;
            }
            else if(max3 < n)
                max3 = n;
        }
        
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};