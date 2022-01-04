class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        vector<int> rows(N, 0);
        vector<int> cols(N, 0);
        vector<int> boxes(N, 0);
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(board[i][j] == '.')
                    continue;
                
                int val = board[i][j] - '0';
                int pos = 1 << (val - 1);
                
                if((rows[i] & pos) != 0)
                    return false;
                
                rows[i] |= pos;
                
                if((cols[j] & pos) != 0)
                    return false;
                
                cols[j] |= pos;
                
                int idx = ((i/3)*3) + (j/3);
                if((boxes[idx] & pos) != 0)
                    return false;
                
                boxes[idx] |= pos;
            }
        }
        
        return true;
    }
    
};