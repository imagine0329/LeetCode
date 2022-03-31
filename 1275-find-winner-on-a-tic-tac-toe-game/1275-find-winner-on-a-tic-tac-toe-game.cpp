class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3;
        int player = 1;
        vector<int> rows(3), cols(3);
        int diagonal = 0, antiDiagonal = 0;
        
        int count = 0;
        for(auto m : moves) {
            count++;
            rows[m[0]] += player;
            cols[m[1]] += player;
            if(m[0] == m[1]) diagonal += player;
            if(m[1] == n - m[0] - 1) antiDiagonal += player;
            
            int win = n * player;
            if(rows[m[0]] == win || cols[m[1]] == win || diagonal == win || antiDiagonal == win)
                return player == 1 ? "A" : "B";
            
            player *= -1;
        }
        
        return count == n * n ? "Draw" : "Pending";
    }
};