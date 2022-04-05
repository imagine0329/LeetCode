class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        int islands = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(!visited[row][col] && grid[row][col] == '1') {
                    islands++;
                    visited[row][col] = true;
                    q.push({row, col});
                    while(!q.empty()) {
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        for(int i = 0; i < 4; i++) {
                            int nr = r + offset[i], nc = c + offset[i + 1];
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] 
                               && grid[nr][nc] == '1') {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};