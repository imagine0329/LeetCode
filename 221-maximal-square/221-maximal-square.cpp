class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int row = 1; row <= m; row++) {
            for(int col = 1; col <= n; col++) {
                if(matrix[row-1][col-1] == '1') {
                    dp[row][col] = min(dp[row-1][col-1], min(dp[row][col-1], dp[row-1][col])) + 1;
                    maxLen = max(maxLen, dp[row][col]);
                }
            }
        }
        
        return maxLen * maxLen;
    }
};