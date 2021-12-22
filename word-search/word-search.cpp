class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                if(backtracking(board, word, row, col, 0))
                    return true;
            }
        }
        
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, string& word, int row, int col, int idx)
    {
        if(idx == word.length())
            return true;
        
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        
        if(word[idx] != board[row][col])
            return false;
        
        board[row][col] = '#';
        
        int rowOffset[4] = {-1, 0, 1, 0};
        int colOffset[4] = {0, -1, 0, 1};
        
        for(int i=0; i<4; i++)
        {
            if(backtracking(board, word, row+rowOffset[i], col+colOffset[i], idx+1))
                return true;
        }
        
        board[row][col] = word[idx];
        
        return false;
    }
};