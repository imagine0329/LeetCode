class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int row=0; row<board.size(); row++)
        {
            for(int col=0; col<board.front().size(); col++)
            {
                if(backtracking(board, word, 0, row, col))
                    return true;
            }
        }
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, string word, int idx, int row, int col)
    {
        if(idx == word.length())
            return true;
        
        if(row < 0 || row >= board.size() || col < 0 || col >= board.front().size())
            return false;
        
        if(word[idx] != board[row][col])
            return false;
        
        board[row][col] = '#';
        
        int rowOffsets[] = {0, 1, 0, -1};
        int colOffsets[] = {1, 0, -1, 0};
        
        for(int i=0; i<4; i++)
        {
            if(backtracking(board, word, idx+1, row+rowOffsets[i], col+colOffsets[i]))
                return true;
        }
        
        board[row][col] = word[idx];
        
        return false;
    }
};