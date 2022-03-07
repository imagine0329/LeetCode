class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int area = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(!visited[row][col] && grid[row][col] == 1)
                    area = max(area, dfs(grid, visited, row, col));
            }
        }
        
        return area;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        visited[row][col] = true;
        
        int area = 0;
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && grid[r][c] == 1)
                area += dfs(grid, visited, r, c);
        }
        
        return area + 1;
    }
};