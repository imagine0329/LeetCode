class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int longest = 1, start = 0;
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            if(i < n - 1 && s[i] == s[i + 1]) {
                longest = 2;
                start = i;
                dp[i][i + 1] = true;
            }
        }
        
        for(int k = 3; k <= n; k++) {
            for(int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if(longest < k) {
                        longest = k;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, longest);
    }
};