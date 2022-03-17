class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n), rank(m * n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        int ans = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1') {
                    ans++;
                    for(int i = 0; i < 4; i++) {
                        int r = row + offset[i], c = col + offset[i + 1];
                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                            if(Union(parent, rank, (row * n) + col, (r * n) + c))
                                ans--;
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    int find(vector<int>& parent, int x) {
        if(parent[x] != x)
            return parent[x] = find(parent, parent[x]);
        return x;
    }
    
    bool Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);
        
        if(x == y) return false;
        
        if(rank[x] >= rank[y]) {
            parent[y] = x;
            rank[x]++;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
        return true;
    }
};