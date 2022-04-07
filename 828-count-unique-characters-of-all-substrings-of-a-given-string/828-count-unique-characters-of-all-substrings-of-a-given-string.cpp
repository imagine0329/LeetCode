class Solution {
public:
    int uniqueLetterString(string s) {
        int index[26][2];
        int n = s.length(), mod = pow(10, 9) + 7;
        int ans = 0;
        
        memset(index, -1, sizeof(int) * 52);
        
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            ans = ans + (i - index[c][1]) * (index[c][1] - index[c][0]);
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        
        for(int i = 0; i < 26; i++)
            ans = ans + (n - index[i][1]) * (index[i][1] - index[i][0]);
        
        return ans;
    }
};