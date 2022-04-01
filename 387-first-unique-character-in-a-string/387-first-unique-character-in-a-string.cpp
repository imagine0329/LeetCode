class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> idx;
        unordered_map<char, bool> unique;
        
        for(int i = 0; i < s.length(); i++) {
            if(idx.find(s[i]) != idx.end())
                unique[s[i]] = false;
            else
                unique[s[i]] = true;
            idx[s[i]] = i;
        }
        
        int ans = INT_MAX;
        for(auto u : unique) {
            if(u.second)
                ans = min(ans, idx[u.first]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};