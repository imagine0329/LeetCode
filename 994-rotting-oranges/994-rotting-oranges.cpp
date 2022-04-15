class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int time = 2;
        
        while(helper(grid, time))
            time++;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1)
                    return -1;
            }
        }
        
        return time - 2;
    }
    
    bool helper(vector<vector<int>>& grid, int time) {
        int m = grid.size(), n = grid[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        bool continued = false;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == time) {
                    for(int i = 0; i < 4; i++) {
                        int r = row + offset[i], c = col + offset[i + 1];
                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                            grid[r][c] = time + 1;
                            continued = true;
                        }
                    }
                }
            }
        }
        
        return continued;
    }
};