class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for(int row = 0; row < m; row++)
            grid[row][0] = 1;
        for(int col = 0; col < n; col++)
            grid[0][col] = 1;
        
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++)
                grid[row][col] = grid[row-1][col] + grid[row][col-1];
        }
        
        return grid[m-1][n-1];
    }
};