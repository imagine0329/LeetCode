class Solution {
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target, 0, matrix[0].size()-1, 0, matrix.size()-1);
    }
    
    bool search(vector<vector<int>>& matrix, int target, int left, int right, int up, int down) {
        if(left > right || up > down)
            return false;
        if(target < matrix[up][left] || target > matrix[down][right])
            return false;
        
        int mid = left + (right - left) / 2;
        int row = up;
        while(row <= down && matrix[row][mid] <= target) {
            if(matrix[row][mid] == target)
                return true;
            
            row++;
        }
        
        return search(matrix, target, left, mid-1, row, down) ||
                search(matrix, target, mid+1, right, up, row-1);
    }
};