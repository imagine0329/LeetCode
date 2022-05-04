class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int row = 1; row < m; row++) {
            bool same = true, opposite = true;
            for(int col = 0; col < n; col++) {
                same = same && grid[0][col] == grid[row][col];
                opposite = opposite && grid[0][col] != grid[row][col];
            }
            
            if(!same && !opposite)
                return false;
        }
        return true;
    }
};
/*

       n
    [0,1,0]
 m  [1,1,1]     
    [0,0,0]
    
    same    opposite
    false   true
    false   false
    false   false

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