/*  Optimized Approach*/
class TicTacToe {
private:
    vector<int> rows, cols;
    int l_diagonal, r_diagonal;
    int n;
    
public:
    TicTacToe(int n) {
        this->n = n;
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        l_diagonal = 0;
        r_diagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int x = player == 1 ? 1 : -1;
        
        rows[row] += x;
        cols[col] += x;
        
        if(row == col)
            l_diagonal += x;
        
        if(row == n - col - 1)
            r_diagonal += x;
        
        int res = n*x;
        if(rows[row] == res || cols[col] == res || l_diagonal == res || r_diagonal == res)
            return player;
        
        return 0;
    }
};


/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */