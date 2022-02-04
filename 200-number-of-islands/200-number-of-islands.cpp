class UnionFind {
private:
    vector<int> parent, rank;
    int count;
    
public:
    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        parent = vector<int>(m * n, -1);
        rank = vector<int>(m * n, 0);
        count = 0;
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                int i = n * r + c;
                if(grid[r][c] == '1') {
                    count++;
                    parent[i] = i;
                }
            }
        }
    }
    
    int find(int x) {
        if(parent[x] != x)
            return parent[x] = find(parent[x]);
        
        return x;
    }
    
    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y)
            return;
        
        if(rank[x] > rank[y]) {
            parent[y] = x;
            rank[x]++;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
        
        count--;
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        UnionFind uf(grid);
        
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1' && !visited[row][col]) {
                    visited[row][col] = true;
                    for(int i = 0; i < 4; i++) {
                        int r = row + offset[i], c = col + offset[i + 1];
                        if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && grid[r][c] == '1') {
                            
                            uf.Union(n * row + col, n * r + c);
                        }
                    }
                }
            }
        }
        
        return uf.getCount();
    }
};