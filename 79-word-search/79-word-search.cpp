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
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        bool ret;
        for(int i=0; i<4; i++)
        {
            ret = backtracking(board, word, row+offset[i], col+offset[i+1], idx+1);
            if(ret)
                break;
        }
        
        board[row][col] = word[idx];
        return ret;
    }
};