class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool negative = false;
        for(auto n : nums) {
            if(n == 0) return 0;
            negative = n < 0 ? !negative : negative;
        }
        
        return negative ? -1 : 1;
    }
};