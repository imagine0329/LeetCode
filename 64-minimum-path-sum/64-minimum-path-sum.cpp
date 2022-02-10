class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n] = 0;
        
        for(int r = m - 1; r >= 0; r--) {
            for(int c = n - 1; c >= 0; c--)
                dp[r][c] = min(dp[r][c], grid[r][c] + min(dp[r + 1][c], dp[r][c + 1]));
        }
        
        return dp[0][0];
    }
};