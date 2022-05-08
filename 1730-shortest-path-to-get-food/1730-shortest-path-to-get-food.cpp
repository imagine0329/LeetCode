class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> offset = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int r = 0; r < n; r++) {
            bool stop = false;
            for(int c = 0; c < m; c++) {
                if(grid[r][c] == '*') {
                    q.push({r, c});
                    visited[r][c] = true;
                    stop = true;
                    break;
                }
            }
            if(stop)
                break;
        }
        
        int step = -1;
        while(!q.empty()) {
            step++;
            int sz = q.size();
            while(sz--) {
                auto cell = q.front(); q.pop();
                int row = cell.first, col = cell.second;
                if(grid[row][col] == '#')
                    return step;
                
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 'X' && !visited[r][c]) {
                        q.push({r, c});
                        visited[r][c] = true;
                    }
                }
            }
        }
        
        return -1;
    }
};

/*
["X","X","X","X","X","X"]
["X","*","v","v","v","X"]
["X","v","v","#","O","X"]
["X","X","X","X","X","X"]
*/