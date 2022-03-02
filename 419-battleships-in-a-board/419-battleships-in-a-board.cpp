class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int count = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(!visited[r][c] && board[r][c] == 'X') {
                    count++;
                    dfs(board, visited, r, c);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        int m = board.size(), n = board[0].size();
        visited[row][col] = true;
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && board[r][c] == 'X') {
                dfs(board, visited, r, c);
            }
        }
    }
};