class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        
        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[m-1][i] == 'O')
                dfs(board, m-1, i);
        }
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(board[row][col] == '#')
                    board[row][col] = 'O';
                else if(board[row][col] == 'O')
                    board[row][col] = 'X';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size(), n = board[0].size();
        board[row][col] = '#';
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'O')
                dfs(board, r, c);
        }
    }
};