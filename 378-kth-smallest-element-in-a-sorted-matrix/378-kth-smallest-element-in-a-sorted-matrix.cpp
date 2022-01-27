class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1];
        int ans = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
    
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0, col = matrix[0].size() - 1;
        for(int row = 0; row < matrix.size(); row++) {
            while(col >= 0 && matrix[row][col] > x) col--;
            cnt += (col + 1);
        }
        return cnt;
    }
};