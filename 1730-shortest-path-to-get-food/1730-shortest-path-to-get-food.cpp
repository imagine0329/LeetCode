class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, false));
        
        int found = false;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '*') {
                    q.push({row, col});
                    visited[row][col] = true;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        
        int len = 0;
        vector<int> offset = {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            len++;
            int sz = q.size();
            while(sz--) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 'X' && !visited[r][c]) {
                        if(grid[r][c] == '#') return len;
                        q.push({r, c});
                        visited[r][c] = true;
                    }
                }
            }
        }
        
        return -1;
    }
};