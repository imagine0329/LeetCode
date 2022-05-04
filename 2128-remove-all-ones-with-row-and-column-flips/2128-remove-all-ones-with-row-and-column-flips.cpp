class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1) {
                for(int j = 0; j < m; j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        
        for(int row = 1; row < m; row++) {
            int sum = 0;
            for(int col = 0; col < n; col++)
                sum += grid[row][col];
            if(sum != 0 && sum != n)
                return false;
        }
        return true;
    }
};
/*

       n
    [0,0,0]
 m  [1,1,1]
    [0,0,0]

[0,0,0]
[0,0,0]
[0,1,0]

[0,0,0]
[1,1,1]
[0,0,0]

1. use exclusive OR to flip
2. flip 2 times = equivalent of not flipping at all
    -> at most one flip per line
3. whatever the order of the flip is, result will always be the same

*/