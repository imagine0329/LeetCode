class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        bool player = true;
        char p;
        vector<vector<char>> board(3, vector<char>(3));
        for(auto move : moves) {
            int r = move[0], c = move[1];
            bool res = false;
            p = player ? 'X' : 'O';
            board[r][c] = p;
            res = checkRow(board, r, player) || checkCol(board, c, player);
            if(!res && r == c)
                res |= checkDiagonal(board, player);
            if(!res && r == 2 - c)
                res |= checkAntiDiagonal(board, player);
                
            if(res) return player ? "A" : "B";
            player = !player;
        }
        
        return moves.size() == 9  ? "Draw" : "Pending";
    }
    
    bool checkRow(vector<vector<char>>& board, int row, bool player) {
        char c = player ? 'X' : 'O';
        for(int col = 0; col < 3; col++) {
            if(board[row][col] != c)
                return false;
        }
        
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int col, bool player) {
        char c = player ? 'X' : 'O';
        for(int row = 0; row < 3; row++) {
            if(board[row][col] != c)
                return false;
        }
        
        return true;
    }
    
    bool checkDiagonal(vector<vector<char>>& board, bool player) {
        char c = player ? 'X' : 'O';
        for(int i = 0; i < 3; i++) {
            if(board[i][i] != c)
                return false;
        }
        
        return true;
    }
    
    bool checkAntiDiagonal(vector<vector<char>>& board, bool player) {
        char c = player ? 'X' : 'O';
        for(int i = 0; i < 3; i++) {
            if(board[2 - i][i] != c)
                return false;
        }
        
        return true;
    }
};




