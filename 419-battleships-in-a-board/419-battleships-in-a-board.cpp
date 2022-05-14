class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(board[row][col] == 'X' && !visited[row][col]) {
                    count++;
                    dfs(board, visited, row, col);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        int m = board.size(), n = board[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        visited[row][col] = true;
        
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && board[r][c] == 'X' && !visited[r][c])
                dfs(board, visited, r, c);
        }
    }
};

/*
["X",".","X","X"]
[".",".",".","X"]
[".",".",".","X"]
[".",".",".","."]
*/