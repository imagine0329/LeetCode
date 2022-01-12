class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0, prev = 0;
        vector<int> dp(n+1, 0);
        
        for(int row = 1; row <= m; row++) {
            for(int col = 1; col <= n; col++) {
                int temp = dp[col];
                if(matrix[row-1][col-1] == '1') {
                    dp[col] = min(dp[col], min(dp[col-1], prev)) + 1;
                    maxLen = max(maxLen, dp[col]);
                }
                else
                    dp[col] = 0;
                
                prev = temp;
            }
        }
        
        return maxLen * maxLen;
    }
};