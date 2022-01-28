class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        unordered_set<int> seen;
        
        for(auto c : s)
            m[c]++;
        
        int ans = 0;
        for(auto[c, freq] : m) {
            while(seen.find(freq) != seen.end()) {
                freq--;
                ans++;
            }
            
            if(freq > 0)
                seen.insert(freq);
        }
        
        return ans;
    }
};