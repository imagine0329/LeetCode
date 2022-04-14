class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0;
        int longest = INT_MIN;
        
        for(auto n : nums) {
            if(n > 0) {
                pos++;
                if(neg != 0)
                    neg++;
                else
                    neg = 0;
            }
            else if(n < 0) {
                int temp = pos;
                
                if(neg != 0)
                    pos = neg + 1;
                else
                    pos = 0;
                
                neg = temp + 1;
                
            }
            else {
                pos = 0;
                neg = 0;
            }
            
            longest = max(longest, pos);
        }
        
        return longest;
    }
};