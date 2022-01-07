class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m == 0 ? 0 : matrix[0].size();
        vector<int> rows(m, 1), cols(n, 1);
        
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(matrix[row][col] == 0)
                {
                    rows[row] = 0;
                    cols[col] = 0;
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            if(rows[i])
                continue;
            
            for(int j=0; j<n; j++)
                matrix[i][j] = 0;
        }
        
        for(int i=0; i<n; i++)
        {
            if(cols[i])
                continue;
            
            for(int j=0; j<m; j++)
                matrix[j][i] = 0;
        }
    }
};