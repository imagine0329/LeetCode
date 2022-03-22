class TicTacToe {
private:
    int n;
    vector<int> rows, cols;
    int diagonal, antiDiagonal;
    
public:
    TicTacToe(int n) {
        this->n = n;
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;
        rows[row] += val;
        cols[col] += val;
        if(row == col) diagonal += val;
        if(col == n - row - 1) antiDiagonal += val;
        
        val *= n;
        if(rows[row] == val || cols[col] == val || diagonal == val || antiDiagonal == val)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */