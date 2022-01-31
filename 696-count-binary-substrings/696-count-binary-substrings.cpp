class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups(s.length());
        groups[0] = 1;
        int k = 0;
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i - 1] != s[i])
                groups[++k] = 1;
            else
                groups[k]++;
        }
        
        int ans = 0;
        for(int i = 1; i <= k; i++)
            ans += min(groups[i - 1], groups[i]);
        
        return ans;
    }
};