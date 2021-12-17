class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false, row0 = false;
        
        for(int i=0; i<matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
                col0 = true;
        }
        
        for(int i=0; i<matrix[0].size(); i++)
        {
            if(matrix[0][i] == 0)
                row0 = true;
        }
        
        for(int row=1; row<matrix.size(); row++)
        {
            for(int col=1; col<matrix[0].size(); col++)
            {
                if(matrix[row][col] == 0)
                {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        
        for(int row=1; row<matrix.size(); row++)
        {
            for(int col=1; col<matrix[0].size(); col++)
            {
                if(matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;
            }
        }
        
        if(col0)
        {
            for(int i=0; i<matrix.size(); i++)
                matrix[i][0] = 0;
        }
        
        if(row0)
        {
            for(int i=0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
    }
};