class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        
        int continued = true;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '*') {
                    q.push({row, col});
                    continued = false;
                    break;
                }
            }
            
            if(continued == false)
                break;
        }
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        int step = 0;
        while(!q.empty()) {
            step++;
            int sz = q.size();
            while(sz--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 'X') {
                        if(grid[r][c] == '#')
                            return step;
                        grid[r][c] = 'X';
                        q.push({r, c});
                    }
                }
            }
        }
        
        return -1;
    }
};