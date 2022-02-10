class Solution {    
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; dp[1] = 1;
        
        return recursive(n, dp);
    }
    
    int recursive(int n, vector<int>& dp) {
        if(dp[n] != 0)
            return dp[n];
        
        int count = 0;
        for(int i = 1; i <= n; i++)
            count += recursive(i - 1, dp) * recursive(n - i, dp);
        
        return dp[n] = count;
    }
};