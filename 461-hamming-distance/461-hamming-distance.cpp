class Solution {
public:
    int hammingDistance(int x, int y) {
        int maxBit = getMaxBit(max(x, y));
        
        int count = 0;
        for(int i = 0; i < maxBit; i++) {
            int mask = 1 << i;
            if((x & mask) != (y & mask))
                count++;
        }
        
        return count;
    }
    
    int getMaxBit(int n) {
        int count = 0;
        while(n) {
            count++;
            n /= 2;
        }
        
        return count;
    }
};