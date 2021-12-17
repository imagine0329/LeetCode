class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        int i=0;
        while(n != 0)
        {
            int set = n & 1;
            
            n >>= 1;
            ans |= (set << (31-i));
            i++;
        }
        
        return ans;
    }
};