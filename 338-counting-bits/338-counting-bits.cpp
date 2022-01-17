class Solution {
public:
    vector<int> countBits(int n) {
        int max_bit = getMaxBit(n);
        vector<int> ret(n + 1, 0);
        
        for(int i = 0; i < max_bit; i++) {
            int mask = 1 << i;
            for(int j = 0; j <= n; j++) {
                if(j & mask)
                    ret[j]++;
            }
        }
        
        return ret;
    }
    
    int getMaxBit(int n) {
        int count = 0;
        while(n) {
            n /= 2;
            count++;
        }
        
        return count;
    }
};