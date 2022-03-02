class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n : nums)
            m[n]++;
        
        int pairs = 0;
        for(auto n : m) {
            int k = n.second - 1;
            pairs += k * (k + 1) / 2;
        }
        
        return pairs;
    }
};