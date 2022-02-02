class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n, 1);
        
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++)
                v[col] = v[col-1] + v[col];
        }
        
        return v[n-1];
    }
};