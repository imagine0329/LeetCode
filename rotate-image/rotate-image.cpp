class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for(int r=0; r<n; r++)
        {
            for(int c=r; c<n-r; c++)
            {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[n-c][n-(n-r)];
                matrix[n-c][n-(n-r)] = matrix[n-r][n-c];
                matrix[n-r][n-c] = matrix[c][n-r];
                matrix[c][n-r] = temp;
                
            }
        }
    }
};