class Solution {
private:
    int maxLen;
    vector<vector<int>> memo;
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        maxLen = 0;
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '1' && memo[row][col] == -1)
                    recur(matrix, row, col);
            }
        }
        
        return maxLen * maxLen;
    }
    
    int recur(vector<vector<char>>& matrix, int row, int col)
    {
        if(row == matrix.size() || col == matrix[0].size())
            return 0;
        
        if(memo[row][col] != -1)
            return memo[row][col];
        
        if(matrix[row][col] == '0')
            return memo[row][col] = 0;
        
        memo[row][col] = min(recur(matrix, row+1, col+1), min(recur(matrix, row+1, col), recur(matrix, row, col+1))) + 1;
        maxLen = max(maxLen, memo[row][col]);
        
        return memo[row][col];
    }
};