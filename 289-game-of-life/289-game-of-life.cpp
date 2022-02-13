class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                int neighbors = countNeighbors(board, row, col);
                if(neighbors == 3 || neighbors - (board[row][col] & 1) == 3)
                    board[row][col] |= 2;
            }
        }
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++)
                board[row][col] >>= 1;
        }
    }
    
    int countNeighbors(vector<vector<int>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        int count = 0;
        for(int row = max(0, r - 1); row < min(m, r + 2); row++) {
            for(int col = max(0, c - 1); col < min(n, c + 2); col++)
                count += (board[row][col] & 1);
        }
        return count;
    }
};