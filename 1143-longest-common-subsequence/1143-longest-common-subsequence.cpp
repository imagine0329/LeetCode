class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        for(int i = 0; i <= n1; i++)
            dp[i][n2] = 0;
        for(int i = 0; i <= n2; i++)
            dp[n1][i] = 0;
        
        for(int r = n1 - 1; r >= 0; r--) {
            for(int c = n2 - 1; c >= 0; c--) {
                if(text1[r] == text2[c])
                    dp[r][c] = dp[r + 1][c + 1] + 1;
                else
                    dp[r][c] = max(dp[r + 1][c], dp[r][c + 1]);
            }
        }
        
        return dp[0][0];
    }
};