class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 2)
                    q.push({row, col});
                if(grid[row][col] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0)
            return 0;
        
        int step = -1;
        vector<int> offset = {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            step++;
            int sz = q.size();
            while(sz--) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r, c});
                    }
                }
            }
            
        }
        
        if(fresh != 0)
            return -1;
        
        return step;
    }
};