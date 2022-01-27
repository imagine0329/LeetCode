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
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int row, int col) {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O')
            return;
        
        board[row][col] = '#';
        
        vector<int> offset = {-1, 0 , 1, 0, -1};
        for(int i = 0; i < 4; i++)
            dfs(board, row + offset[i], col + offset[i + 1]);
    }
};