class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(backtracking(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, string word, int row, int col, int idx)
    {
        if(idx == word.length())
            return true;
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        
        if(board[row][col] != word[idx])
            return false;
        
        board[row][col] = '#';
        
        int rowOffsets[] = {0, 1, 0, -1};
        int colOffsets[] = {1, 0, -1, 0};
        
        for(int i=0; i<4; i++)
        {
            if(backtracking(board, word, row+rowOffsets[i], col+colOffsets[i], idx+1))
                return true;
        }
        
        board[row][col] = word[idx];
        return false;
    }
};