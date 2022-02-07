class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        offset = {-1, 0, 1, 0, -1};
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int longest = 0;
        for(int row = 0; row < matrix.size(); row++) {
            for(int col = 0; col < matrix[0].size(); col++)
                longest = max(longest, dfs(matrix, memo, row, col));
        }
        
        return longest;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int row, int col) {
        if(memo[row][col] != 0) return memo[row][col];
        
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size() && matrix[row][col] < matrix[r][c])
                memo[row][col] = max(memo[row][col], dfs(matrix, memo, r, c));
        }
        
        return ++memo[row][col];
    }
    
private:
    vector<int> offset;
};