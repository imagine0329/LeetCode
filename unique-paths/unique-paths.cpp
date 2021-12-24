class Solution {
vector<vector<int>> memo;
    
public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        memo[0][0] = 1;
        
        return findPaths(m-1, n-1);
    }
    
    int findPaths(int row, int col)
    {
        if(row < 0 || col < 0)
            return 0;
        
        if(memo[row][col] == -1)
            memo[row][col] = findPaths(row-1, col) + findPaths(row, col-1);
        
        return memo[row][col];
    }
};