class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        for(int j = 0; j <= n; j++) {
            dp[j] = j;
            for(int i = 1; i < j - 2; i++) {
                dp[j] = max(dp[j], dp[i] * (j - i - 1));
            }
        }
        
        
        return dp[n];
        
    }
};