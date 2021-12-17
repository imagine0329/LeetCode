class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        
        for(int row=0; row<matrix.size(); row++)
        {
            for(int col=0; col<matrix.front().size(); col++)
            {
                if(matrix[row][col] == 0)
                {
                    rows.insert(row);
                    cols.insert(col);
                }
            }
        }
        
        for(int row=0; row<matrix.size(); row++)
        {
            for(int col=0; col<matrix.front().size(); col++)
            {
                if(rows.find(row) != rows.end() || cols.find(col) != cols.end())
                    matrix[row][col] = 0;
            }
        }
    }
};