class Solution {
private:
    
    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int t = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        while(!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int row = cell[1], col = cell[2];
            t = max(t, cell[0]);
            
            if(row == n - 1 && col == n - 1)
                return t;
            
            for(int i = 0; i < 4; i++) {
                int r = row + offset[i], c = col + offset[i + 1];
                if(r >= 0 && r < n && c >= 0 && c < n && !visited[r][c]) {
                    visited[r][c] = true;
                    pq.push({grid[r][c], r, c});
                }
            }
        }
        
        return t;
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