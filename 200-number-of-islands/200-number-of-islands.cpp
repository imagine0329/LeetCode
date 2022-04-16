class UnionFind {
private:
    vector<int> parent, rank;
    int count = 0;
    
public:
    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        parent = vector<int>(m * n);
        rank = vector<int>(m * n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1')
                    count++;
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
        
        if(rank[x] >= rank[y]) {
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

//num = (r * n) + c

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        UnionFind uf(grid);
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == '1') {
                    for(int i = 0; i < 4; i++) {
                        int r = row + offset[i], c = col + offset[i + 1];
                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                            uf.Union((row * n) + col, (r * n) + c);
                        }
                    }   
                }
            }
        }
        
        return uf.getCount();
    }
};