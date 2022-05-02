class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] > 0 && row > 0 && col > 0) 
                    matrix[row][col] = min(matrix[row - 1][col - 1], min(matrix[row][col - 1], matrix[row - 1][col])) + 1;
                count += matrix[row][col];
            }
        }
        return count;
    }
};
/*
    [0, 1, 1, 1],
    [1, 1, 1, 1],
    [0, 1, 1, 1]
    
       0  0  0  0
    0 [0, 1, 1, 1],
    0 [1, 1, 2, 2],
    0 [0, 1, 2, 3]
    
    dp(i, j) = min(dp(i - 1, j - 1), dp(i - 1, j), dp(i, j - 1)) + 1
    if(dp(i, j) > 1)
        count++


*/