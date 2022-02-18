class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<vector<int>> matrix = {{1, 1}, {1, 0}};
        matrixPower(matrix, n - 1);
        return matrix[0][0];
    }
    
    void matrixPower(vector<vector<int>>& matrix, int n) {
        if(n <= 1) return;
        matrixPower(matrix, n / 2);
        multiply(matrix, matrix);
        
        if(n & 1) {
            vector<vector<int>> def = {{1, 1}, {1, 0}};
            multiply(matrix, def);
        }
    }
    
    void multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int x = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        int y = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        int z = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        int w = a[1][0] * b[0][1] + a[1][1] * b[1][1];
        
        a[0][0] = x;
        a[0][1] = y;
        a[1][0] = z;
        a[1][1] = w;
    }
};