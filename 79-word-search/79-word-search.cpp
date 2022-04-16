class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(backtracking(board, word, 0, row, col, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, string word, int idx, int row, int col,
                     vector<vector<bool>>& visited) {
        int m = board.size(), n = board[0].size();
        if(word.length() == idx)
            return true;
        
        if(row < 0 || row >= m || col < 0 || col >= n || visited[row][col])
            return false;
        
        if(word[idx] != board[row][col])
            return false;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        visited[row][col] = true;
        
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(backtracking(board, word, idx + 1, r, c, visited))
                return true;
        }
        visited[row][col] = false;
        return false;
    }
};