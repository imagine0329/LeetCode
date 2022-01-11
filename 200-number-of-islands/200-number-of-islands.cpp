class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == '1')
                {
                    islands++;
                    dfs(grid, row, col);
                }
            }
        }
        
        return islands;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        int m = grid.size(), n = grid[0].size();
        
        grid[row][col] = '0';
        
        if(row-1 >= 0 && grid[row-1][col] == '1')   dfs(grid, row-1, col);
        if(row+1 < m && grid[row+1][col] == '1')    dfs(grid, row+1, col);
        if(col-1 >= 0 && grid[row][col-1] == '1')   dfs(grid, row, col-1);
        if(col+1 < n && grid[row][col+1] == '1')    dfs(grid, row, col+1);
    }
};