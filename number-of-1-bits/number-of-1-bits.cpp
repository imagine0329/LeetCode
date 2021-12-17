class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t checker = 1;
        
        int count = 0;
        for(int i=0; i<32; i++)
        {
            if(n & checker)
                count++;
            
            checker <<= 1;
        }
        
        return count;
    }
};