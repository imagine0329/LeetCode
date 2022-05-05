class Solution {
private:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> adj;
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int t = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        dfs(grid, 0, 0, t, visited);
        return t;
    }
    
    bool dfs(vector<vector<int>>& grid, int row, int col, int& t, vector<vector<bool>>& visited) {
        int n = grid.size();
         
        if(grid[row][col] > t)
            t = grid[row][col];
        
        if(row == n - 1 && col == n - 1)
            return true;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        visited[row][col] = true;
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < n && c >= 0 && c < n && !visited[r][c])
                adj.push({grid[r][c], r, c});
        }
        
        vector<int> next = adj.top();
        adj.pop();
        
        if(dfs(grid, next[1], next[2], t, visited))
            return true;
        
        visited[row][col] = false;
        return false;
    }
};
/*
[10,12,4,6],
[9,11,3,5],
[1,7,13,8],
[2,0,15,14]



[ 0, 1, 2, 3, 4]
[24,23,22,21, 5]
[12,13,14,15,"16"]  t = 6   wait = 10
[11,"17","18",19,20]  t = 16  wait = 1      t = 17  wait = 1
[10, 9, 18, 7, 6]

find min among 4-direction
if(min > t)
    t <- min
    
[ 0, 1, 2, 3, 4]
[24,23, 9,10, 5]
[12,13, 8, 7, 6]
[11,17,18,19,20]
[10, 9, 8, 7, 6]

min_heap: 24 23 20 19 18 23

*/