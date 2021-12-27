class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                int count = 0;
                for(int i=max(row-1, 0); i<min(row+2, m); i++) {
                    for(int j=max(col-1, 0); j<min(col+2, n); j++)
                        count += board[i][j] & 1;
                }
                
                if(count == 3 || count - board[row][col] == 3)
                    board[row][col] |= 2;
            }
        }
        
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++)
                board[row][col] >>= 1;
        }
    }
};