class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<set<pair<int, int>>> unique;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(!visited[row][col] && grid[row][col] == 1) {
                    set<pair<int, int>> island;
                    dfs(grid, visited, island, row, col, row, col);
                    unique.insert(island);
                }
            }
        }
        
        return unique.size();
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, set<pair<int, int>>& island, 
             int sr, int sc, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        visited[row][col] = true;
        island.insert({row - sr, col - sc});
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && grid[r][c] == 1)
                dfs(grid, visited, island, sr, sc, r, c);
        }
    }
};