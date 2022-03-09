class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> idx(26, vector<int>(2, -1));
        int n = s.length(), mod = pow(10, 9) + 7;
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            res = (res + (i - idx[c][1]) * (idx[c][1] - idx[c][0]) % mod) % mod;
            idx[c][0] = idx[c][1];
            idx[c][1] = i;
        }
        
        for(int c = 0; c < 26; c++)
            res = (res + (n - idx[c][1]) * (idx[c][1] - idx[c][0]) % mod) % mod;
        
        return res;
    }
};