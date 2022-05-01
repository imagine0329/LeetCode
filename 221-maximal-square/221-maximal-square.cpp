class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int row = 1; row < m + 1; row++) {
            for(int col = 1; col < n + 1; col++) {
                if(matrix[row - 1][col - 1] == '1') {
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
                    maxLen = max(maxLen, dp[row][col]);
                }
            }
        }
        return maxLen * maxLen;
    }
};
/*

    0   1   2   3   4
0 ["1","0","1","0","0"],
1 ["1","0","1","1","1"],
2 ["1","1","1","1","1"],
3 ["1","0","0","1","0"]
length = 1
from (r, c) to (r + len, c + len)

    
    0   1   2   3   4
0 [ 1 ,"0", 1 ,"0","0"],
1 [ 1 ,"0", 1 , 1 , 1 ],
2 [ 1 , 1 , 2 , 2 , 2 ],
3 [ 1 ,"0", 1 , 2 , 3 ]
dp(i, j) = min(dp(i-1, j-1), dp(i-1, j), dp(i, j-1)) + 1
*/