class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == '*') {
                    q.push({row, col});
                    break;
                }
            }
        }
        
        int path = 0;
        while(!q.empty()) {
            ++path;
            int n = q.size();
            while(n--) {
                auto cell = q.front(); q.pop();
                int row = cell.first, col = cell.second;
                
                //visited[row][col] = true;
                for(int i = 0; i < 4; i++) {
                    int r = row + offset[i], c = col + offset[i + 1];
                    if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] != 'X') {// && !visited[r][c]) 
                        if(grid[r][c] == '#')
                            return path;
                        q.push({r, c});
                        grid[r][c] = 'X';
                    }
                        
                }
            }
        }
        
        return -1;
    }
};