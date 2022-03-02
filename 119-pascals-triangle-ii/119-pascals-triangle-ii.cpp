class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<vector<int>> memo(rowIndex + 1, vector<int>(rowIndex + 1, 0));
        
        for(int i = 0; i <= rowIndex; i++)
            ans.push_back(getNum(rowIndex, i, memo));
        
        return ans;
    }
    
    int getNum(int row, int col, vector<vector<int>>& memo) {
        if(row == 0 || col == 0 || row == col)
            return 1;
        
        if(memo[row][col] != 0) return memo[row][col];
        
        return memo[row][col] = getNum(row - 1, col - 1, memo) + getNum(row - 1, col, memo);
    }
};