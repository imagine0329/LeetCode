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
        if(row == grid.size() || row < 0 || col == grid[0].size() || col < 0)
            return;
        
        if(grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++)
            dfs(grid, row+offset[i], col+offset[i+1]);
    }
};