class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < time.size(); i++) {
            int x = time[i] % 60;
            cnt += x == 0 ? m[x] : m[60 - x];
            m[x]++;
        }
        
        return cnt;
    }
};