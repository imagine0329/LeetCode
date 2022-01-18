class TicTacToe {
private:
    vector<int> rows, cols;
    int diagonal, antidiagonal;
    int n;
    
public:
    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        antidiagonal = 0;
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        
        rows[row] += add;
        cols[col] += add;
        
        if(row == col)
            diagonal += add;
        if(col == n - row - 1)
            antidiagonal += add;
        
        int val = add * n;
        if(rows[row] == val || cols[col] == val || diagonal == val || antidiagonal == val)
            return player;
            
        return 0;
    }
};


/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */