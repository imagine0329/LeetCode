class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> unique;
        vector<vector<int>> island;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(!visited[row][col] && grid[row][col] == 1) {
                    dfs(grid, visited, island, row, col);
                    for(auto& cell : island) {
                        cell[0] -= row;
                        cell[1] -= col;
                    }
                    if(isUnique(unique, island))
                        unique.push_back(island);
                    island.clear();
                }
            }
        }
        
        return unique.size();
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<int>>& island, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        visited[row][col] = true;
        island.push_back({row, col});
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && grid[r][c] == 1)
                dfs(grid, visited, island, r, c);
        }
    }
    
    bool isUnique(vector<vector<vector<int>>>& unique, vector<vector<int>>& island) {
        for(auto& u : unique) {
            if(u.size() != island.size()) continue;
            if(isEqual(u, island)) return false;
        }
        return true;
    }
    
    bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i][0] != b[i][0] || a[i][1] != b[i][1])
                return false;
        }
        return true;
    }
};