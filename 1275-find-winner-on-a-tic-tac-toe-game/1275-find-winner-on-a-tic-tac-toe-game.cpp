class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3;
        vector<int> rows(n, 0), cols(n, 0);
        int diagonal = 0, antiDiagonal = 0;
        int player = 1;
        
        for(auto move : moves) {
            int r = move[0], c = move[1];
            rows[r] += player;
            cols[c] += player;
            if(r == c)
                diagonal += player;
            if(r == n - c - 1)
                antiDiagonal += player;
            
            int win = player * n;
            if(rows[r] == win || cols[c] == win || diagonal == win || antiDiagonal == win)
                return player == 1 ? "A" : "B";
            
            player *= -1;
        }
        
        if(moves.size() == n * n)
            return "Draw";
        else
            return "Pending";
    }
};