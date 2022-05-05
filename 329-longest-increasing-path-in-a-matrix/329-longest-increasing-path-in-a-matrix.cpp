class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int longest = 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++)
                dfs(matrix, row, col, 1, longest, memo);
        }
        
        return longest;
    }
    
    int dfs(vector<vector<int>>& matrix, int row, int col, int path, int& longest, vector<vector<int>>& memo) {
        
        if(memo[row][col] != -1)
            return memo[row][col];
            
        int m = matrix.size(), n = matrix[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        int len = 1;
        memo[row][col] = 0;
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && matrix[row][col] < matrix[r][c] && memo[r][c] != 0)
                len = max(len, dfs(matrix, r, c, path + 1, longest, memo) + 1);
        }
        
        longest = max(longest, len);
        return memo[row][col] = len;
    }
};

/*
[9,9,4]
[6,6,8]
[2,1,1]
*/