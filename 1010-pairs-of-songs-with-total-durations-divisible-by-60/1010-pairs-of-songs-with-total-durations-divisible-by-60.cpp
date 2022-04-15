class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        vector<int> mod(60, 0);
        
        for(auto t : time)
            mod[t % 60]++;
        
        if(mod[0] > 0)
            cnt += ((long)mod[0] * (mod[0] - 1)) >> 1;
        if(mod[30] > 0)
            cnt += ((long)mod[30] * (mod[30] - 1)) >> 1;
        
        for(int i = 1; i < 30; i++)
            cnt += (mod[i] * mod[60 - i]);
        
        return cnt;
    }
};
