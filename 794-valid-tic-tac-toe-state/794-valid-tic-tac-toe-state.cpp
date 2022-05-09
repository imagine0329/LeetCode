class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int O = 0, X = 0;
        
        for(auto r : board) {
            for(auto c : r) {
                if(c == 'X')
                    X++;
                else if(c == 'O')
                    O++;
            }
        }
        
        if(X == O)
            return !isWin(board, 'X');
        else if(X == O + 1)
            return !isWin(board, 'O');
        else
            return false;
    }
    
    bool isWin(vector<string>& board, char player) {
        int rows[3] = {0}, cols[3] = {0};
        int diagonal = 0, antiDiagonal = 0;
        
        for(int r = 0; r < 3; r++) {
            for(int c = 0; c < 3; c++) {
                if(board[r][c] == player) {
                    rows[r]++;
                    cols[c]++;
                    if(r == c)
                        diagonal++;
                    if(r == 3 - c - 1)
                        antiDiagonal++;

                    if(rows[r] == 3 || cols[c] == 3 || diagonal == 3 || antiDiagonal == 3)
                        return true;
                }
            }
        }
        return false;
    }
};
