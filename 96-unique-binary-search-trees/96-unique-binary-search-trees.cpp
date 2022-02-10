class Solution {    
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; dp[1] = 1;
        
        for(int k = 2; k <= n; k++) {
            for(int i = 1; i <= k; i++)
                dp[k] += dp[i - 1] * dp[k - i];
        }
        
        return dp[n];
    }
};