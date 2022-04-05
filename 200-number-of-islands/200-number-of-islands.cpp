class UnionFind {
private:
    vector<int> parent, rank;
    int count = 0;
    
public:
    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        rank = vector<int>(m * n, 0);
        
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == '1') {
                    parent.push_back(r * n + c);
                    count++;
                }
                else
                    parent.push_back(-1);
            }
        }
    }
    
    int find(int x) {
        if(parent[x] != x)
            return parent[x] = find(parent[x]);
        return x;
    }
    
    bool Union(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y)
            return false;
        
        if(rank[x] >= rank[y]) {
            parent[y] = x;
            rank[x]++;
        }
        else {
            parent[x] = y;
            rank[y]++;
        }
        count--;
        return true;
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> offset = {-1, 0, 1, 0, -1};
        
        UnionFind uf(grid);
        int ans = 0;
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == '1') {
                    ans++;
                    for(int i = 0; i < 4; i++) {
                        int row = r + offset[i], col = c + offset[i + 1];
                        if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1') {
                            if(uf.Union(r * n + c, row * n + col))
                                ans--;
                        }
                            
                    }
                }
            }
        }
        
        return ans;
    }
};