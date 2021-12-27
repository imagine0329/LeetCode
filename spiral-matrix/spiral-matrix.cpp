class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int m = matrix.size(), n = matrix[0].size();
        int direction = 1;
        int i = 0, j = -1;
        
        while(m * n > 0)
        {
            for(int k=0; k<n; k++)
            {
                j += direction;
                ans.push_back(matrix[i][j]);
            }
            
            m -= 1;
            for(int k=0; k<m; k++)
            {
                i += direction;
                ans.push_back(matrix[i][j]);
            }
            
            n -= 1;
            direction *= -1;
        }
        
        return ans;
        
    }
};