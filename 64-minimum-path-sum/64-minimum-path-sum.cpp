class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        return backtracking(grid, dp, 0, 0);
    }
    
    int backtracking(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if(dp[row][col] != INT_MAX)
            return dp[row][col];
        if(row == m - 1 && col == n - 1)
            return dp[row][col] = grid[row][col];
        
        if(row + 1 < m)
            dp[row][col] = backtracking(grid, dp, row + 1, col);
        if(col + 1 < n)
            dp[row][col] = min(dp[row][col], backtracking(grid, dp, row, col + 1));
        
        dp[row][col] += grid[row][col];
        return dp[row][col];
    }
};