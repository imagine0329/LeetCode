class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> tree;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        this->matrix = vector<vector<int>>(m, vector<int>(n));
        this->tree = vector<vector<int>>(m + 1, vector<int>(n + 1));
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++)
                update(r, c, matrix[r][c]);
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - matrix[row][col];
        matrix[row][col] = val;
        for(int r = row + 1; r <= matrix.size(); r += r & (-r)) {
            for(int c = col + 1; c <= matrix[0].size(); c += c & (-c))
                tree[r][c] += delta;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2 + 1, col2 + 1) + sum(row1, col1) - sum(row1, col2 + 1) - sum(row2 + 1, col1);
    }
    
    int sum(int row, int col) {
        int sum = 0;
        for(int r = row; r > 0; r -= r & (-r)) {
            for(int c = col; c > 0; c -= c & (-c))
                sum += tree[r][c];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */