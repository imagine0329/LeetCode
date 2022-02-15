class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int leftHalf = countLeftHalf(matrix, mid);
            if(leftHalf >= k) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
    
    int countLeftHalf(vector<vector<int>>& matrix, int val) {
        int n = matrix.size();
        int count = 0;
        for(int row = n - 1; row >= 0; row--) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] > val)
                    break;
                
                count++;
            }
        }
        
        return count;
    }
};