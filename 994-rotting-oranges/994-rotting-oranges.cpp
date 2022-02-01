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
                else if(grid[row][col] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        
        int num = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                
                vector<int> offset = {-1, 0, 1, 0, -1};
                for(int i = 0; i < 4; i++) {
                    int adj_r = r + offset[i], adj_c = c + offset[i + 1];
                    if(adj_r >= 0 && adj_r < m && adj_c >= 0 && adj_c < n
                        && grid[adj_r][adj_c] == 1) {
                        grid[adj_r][adj_c] = 2;
                        fresh--;
                        q.push({adj_r, adj_c});
                    }
                }
            }
            
            num++;
        }
        
        return fresh == 0 ? num : -1;
    }
};