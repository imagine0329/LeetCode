class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        
        while(left <= right) {
            int pivot = left + (right - left) / 2;
            int val = matrix[pivot / n][pivot % n];
            
            if(val == target)
                return true;
            else if(val < target)
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        
        return false;
    }
};