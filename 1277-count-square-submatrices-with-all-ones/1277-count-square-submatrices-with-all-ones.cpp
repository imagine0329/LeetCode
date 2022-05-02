class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == 1) {
                    count++;
                    int len = 1;
                    bool flag = true;
                    
                    while(row + len < m && col + len < n && flag) {
                        for(int r = row; r <= row + len; r++) {
                            if(matrix[r][col + len] == 0) {
                                flag = false;
                                break;
                            }
                        }
                        
                        for(int c = col; c <= col + len; c++) {
                            if(matrix[row + len][c] == 0) {
                                flag = false;
                                break;
                            }
                        }
                        
                        if(flag) {
                            count++;
                            len++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
/*

    [0, 1, 1, 1],
    [1, 1, 1, 1],
    [0, 1, 1, 1]
    
    [0, 1, 2, 3],
    [1, 2, 2, 3],
    [0, 3, 3, 3]
len = 2, 3, ...

*/