class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;
        
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(!visited[row][col] && grid[row][col] == '1')
                {
                    islands++;
                    dfs(grid, visited, row, col);
                }
            }
        }
        
        return islands;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col)
    {
        if(row == grid.size() || row < 0 || col == grid[0].size() || col < 0)
            return;
        
        if(visited[row][col])
            return;
        
        visited[row][col] = true;
        
        if(grid[row][col] == '0')
            return;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++)
            dfs(grid, visited, row+offset[i], col+offset[i+1]);
    }
};