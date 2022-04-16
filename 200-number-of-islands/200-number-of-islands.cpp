class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1' && !visited[row][col]) {
                    islands++;
                    bfs(grid, visited, row, col);
                }
            }
        }
        
        return islands;
    }
    
    
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        
        q.push({row, col});
        visited[row][col] = true;
        
        while(!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int r = row + offset[i], c = col + offset[i + 1];
                if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && grid[r][c] == '1') {
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }
};