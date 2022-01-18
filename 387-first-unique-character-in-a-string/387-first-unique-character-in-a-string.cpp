class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set<char> seen;
        unordered_map<char, int> m;
        
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(seen.find(c) != seen.end())
                m.erase(c);
            else {
                seen.insert(c);
                m[c] = i;
            }
        }
        
        int idx = INT_MAX;
        for(auto e : m)
            idx = min(idx, e.second);
        
        return idx == INT_MAX ? -1 : idx;
    }
};