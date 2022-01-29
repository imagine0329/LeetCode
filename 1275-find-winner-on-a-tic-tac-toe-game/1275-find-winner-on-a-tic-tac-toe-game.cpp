class Solution {   
public:
    string tictactoe(vector<vector<int>>& moves) {
        int player = 1;
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int diagonal = 0, antiDiagonal = 0;

        for(auto move : moves) {
            int r = move[0], c = move[1];
            rows[r] += player;
            cols[c] += player;
            if(r == c) diagonal += player;
            if(r == 2 - c) antiDiagonal += player;
            
            int res = player * 3;
            if(rows[r] == res || cols[c] == res || diagonal == res || antiDiagonal == res)
                return player == 1 ? "A" : "B";
            player *= -1;
        }
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};