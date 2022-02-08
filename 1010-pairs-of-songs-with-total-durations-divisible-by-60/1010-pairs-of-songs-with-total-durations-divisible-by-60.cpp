class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        unordered_map<int, int> mod;
        
        for(auto n : time) {
            int x = n % 60;
            count += x == 0 ? mod[x] : mod[60 - x];
            mod[x]++;
        }
        
        return count;
    }
};