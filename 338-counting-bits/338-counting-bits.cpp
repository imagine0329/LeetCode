class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);
        int x = 0, b = 1;
        
        while(b <= n) {
            while(x < b && x + b <= n) {
                ret[x + b] = ret[x] + 1;
                x++;
            }
            x = 0;
            b <<= 1;
        }
        
        return ret;
    }
};