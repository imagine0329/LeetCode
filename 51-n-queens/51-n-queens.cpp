class Solution {
private:
    bool cols[20] = {false};
    bool ld[20] = {false};
    bool rd[20] = {false};
    int n;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> ans;
        
        string temp = "";
        for(int i=0; i<n; i++)
            temp += '.';
        
        vector<string> board(n, temp);
        
        backtracking(ans, board, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<string>>& ans, vector<string>& board, int row)
    {
        if(row == board.size())
        {
            ans.push_back(board);
            return;
        }
        
        for(int col=0; col<board.size(); col++)
        {
            if(cols[col] || ld[row-col+(n-1)] || rd[row+col])
                continue;
            
            cols[col] = ld[row-col+(n-1)] = rd[row+col] = true;
            board[row][col] = 'Q';
            backtracking(ans, board, row+1);
            board[row][col] = '.';
            cols[col] = ld[row-col+(n-1)] = rd[row+col] = false;
        }
    }
    
};
