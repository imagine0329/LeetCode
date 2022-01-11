class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int islands = 0;
        
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == '1'){
                    islands++;
                    q.push({row, col});
                    while(!q.empty())
                    {
                        int r = q.front().first, c = q.front().second;
                        q.pop();
                        
                        if(r-1 >= 0 && grid[r-1][c] == '1') {
                            q.push({r-1, c}); grid[r-1][c] = '0';
                        }
                        if(r+1 < m && grid[r+1][c] == '1') {
                            q.push({r+1, c}); grid[r+1][c] = '0';
                        }
                        if(c-1 >= 0 && grid[r][c-1] == '1') {
                            q.push({r, c-1}); grid[r][c-1] = '0';
                        }
                        if(c+1 < n && grid[r][c+1] == '1') {
                            q.push({r, c+1}); grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        
        return islands;
    }
};