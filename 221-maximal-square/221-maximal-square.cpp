class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;
        vector<int> dp(n + 1, 0);
        int prev = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                int temp = dp[col + 1];
                if(matrix[row][col] == '1') {
                    dp[col + 1] = min(dp[col + 1], min(dp[col], prev)) + 1;
                    maxLen = max(maxLen, dp[col + 1]);
                }
                else
                    dp[col + 1] = 0;
                prev = temp;
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

    0   1   2   3   4
 dp[0, pre,  0,  0,  0]
      [x][cur]
  
    dp[col] = min(dp[col], dp[col-1], pre) + 1
    pre = dp[col]
*/