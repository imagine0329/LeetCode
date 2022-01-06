class Solution {
private:
    int m, n;
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = m == 0 ? 0 : matrix[0].size();
        int left = 0, right = n-1, up = 0, down = m-1;
        
        vector<int> ans;
        
        while(left <= right && up <= down)
        {
            for(int col=left; col<=right; col++)
                ans.push_back(matrix[up][col]);
            
            if(++up > down)
                break;
            
            for(int row=up; row<=down; row++)
                ans.push_back(matrix[row][right]);
            
            if(--right < left)
                break;
            
            for(int col=right; col>=left; col--)
                ans.push_back(matrix[down][col]);
            
            if(--down < up)
                break;
            
            for(int row=down; row>=up; row--)
                ans.push_back(matrix[row][left]);
            
            if(++left > right)
                break;
        }
        
        
        return ans;
    }
};