class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int isCol = false;
        
        for(int row=0; row<m; row++)
        {
            if(matrix[row][0] == 0)
                isCol = true;
            
            for(int col=1; col<n; col++)
            {
                if(matrix[row][col] == 0)
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        
        for(int row=1; row<m; row++)
        {
            for(int col=1; col<n; col++)
            {
                if(matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;
            }
        }
        
        if(matrix[0][0] == 0)
        {
            for(int col=0; col<n; col++)
                matrix[0][col] = 0;
        }
        
        if(isCol)
        {
            for(int row=0; row<m; row++)
                matrix[row][0] = 0;
        }
    }
};