class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> board(8, vector<bool>(8, false));
        
        for(auto q : queens)
            board[q[0]][q[1]] = true;
        
        vector<vector<int>> ans;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                int row = king[0] + i, col = king[1] + j;
                while(min(row, col) >= 0 && max(row, col) < 8) {
                    if(board[row][col]) {
                        ans.push_back({row, col});
                        break;
                    }
                    row += i; col += j;
                }
            }
        }
        return ans;
    }
};