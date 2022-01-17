class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);
        
        for(int i = 0; i <= n; i++)
            ret[i] = popCount(i);
        
        return ret;
    }
    
    int popCount(int n) {
        int count = 0;
        while(n) {
            n &= n - 1;
            count++;
        }
        
        return count;
    }
};