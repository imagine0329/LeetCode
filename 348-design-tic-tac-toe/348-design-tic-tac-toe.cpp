class TicTacToe {
private:
    vector<vector<int>> board;
    int n;
    
    bool checkVertical(int col, int player) {
        for(int row = 0; row < n; row++) {
            if(board[row][col] != player)
                return false;
        }
        
        return true;
    }
    
    bool checkHorizontal(int row, int player) {
        for(int col = 0; col < n; col++) {
            if(board[row][col] != player)
                return false;
        }
        
        return true;
    }
    
    bool checkDiagonal(int player) {
        for(int i = 0; i < n; i++) {
            if(board[i][i] != player)
                return false;
        }
        
        return true;
    }
    
    bool checkAntidiagonal(int player) {
        for(int row = 0; row < n; row++) {
            if(board[row][n - row - 1] != player)
                return false;
        }
        
        return true;
    }
    
public:
    TicTacToe(int n) {
        board = vector<vector<int>>(n, vector<int>(n, 0));
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        if(checkVertical(col, player) || checkHorizontal(row, player))
            return player;
        
        if(row == col && checkDiagonal(player))
            return player;
        if(col == n - row - 1 && checkAntidiagonal(player))
            return player;
        
        return 0;
    }
};


/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */