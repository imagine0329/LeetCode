class Solution {
private:
    int n;
    int cl[20] = {0};
    int ld[20] = {0};
    int rd[20] = {0};
    
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> ans;
        
        string temp;
        for(int i=0; i<n; i++)
            temp += ".";
        
        vector<string> board(n, temp);
        
        backtrack(board, ans, 0);
        
        return ans;
    }
    
    void backtrack(vector<string>& board, vector<vector<string>>& ans, int col)
    {
        if(col >= n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(cl[row] == 0 && ld[row-col+(n-1)] == 0 && rd[row+col] == 0)
            {
                board[row][col] = 'Q';
                cl[row] = ld[row-col+(n-1)] = rd[row+col] = 1;
                
                backtrack(board, ans, col+1);
                
                board[row][col] = '.';
                cl[row] = ld[row-col+(n-1)] = rd[row+col] = 0;
            }
        }
    }
};
/*
create board n x n filled with '.'
for column: 0 to n-1
    nQueens(board, column, ans)
    
bool nQueens(board, column, ans)
    if column >= n
        return true;

    for row: 0 to n-1
        check 
        - cl: current row on the left side
        - left and right diagonal
            ld: left diagonal index = row-col+(n-1)
            rd: right diagonal index = row+col
        if all of those is 0
            board[row][column] = 'Q'
            
            ld[row-col+(n-1)] = rd[row+col] = cl[row] = 1
            
            recur this function with col+1
            if nQueens(board, column+1, ans) retuns true
                return true
                
            board[row][column] = '.'
            ld[row-col+(n-1)] = rd[row+col] = cl[row] = 0
        
        if row = n-1
            ans.push_back(board)
                
    return false;
*/