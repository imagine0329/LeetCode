class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int pairs = 0;
        for(auto n : nums) {
            pairs += m[n]++;
        }
        
        return pairs;
    }
};