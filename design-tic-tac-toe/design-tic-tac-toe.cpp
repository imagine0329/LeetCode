class TicTacToe {
private:
    int boardSize;
    vector<vector<int>> board;
    
public:
    TicTacToe(int n) {
        this->boardSize = n;
        board.assign(n, vector<int>(n, 0));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        if(checkCol(row, player) ||
          checkRow(col, player) ||
          (row == col && checkDiagonal(player)) ||
          (row == boardSize-col-1 && checkAntiDiagonal(player))){
            return player;
        }
        
        return 0;
    }
    
    bool checkCol(int row, int player)
    {
        for(int i=0; i<boardSize; i++)
        {
            if(board[row][i] != player)
                return false;
        }
        
        return true;
    }
    
    bool checkRow(int col, int player)
    {
        for(int i=0; i<boardSize; i++)
        {
            if(board[i][col] != player)
                return false;
        }
        
        return true;
    }
    
    bool checkDiagonal(int player)
    {
        for(int i=0; i<boardSize; i++)
        {
            if(board[i][i] != player)
                return false;
        }
        
        return true;
    }
    
    bool checkAntiDiagonal(int player)
    {
        for(int i=0; i<boardSize; i++)
        {
            if(board[i][boardSize-i-1] != player)
                return false;
        }
        
        return true;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */