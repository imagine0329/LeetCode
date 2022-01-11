class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == '1') {
                    parent.push_back(row * n + col);
                    ++count;
                }
                else
                    parent.push_back(-1);
                
                rank.push_back(0);
            }
        }
    }
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX == rootY)
            return;
        
        if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        --count;
    }
    
    int getCount() {
        return count;
    }
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(grid);
        
        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == '1') {
                    grid[row][col] = '0';
                    if(row-1 >= 0 && grid[row-1][col] == '1')   uf.Union(row*n+col, (row-1)*n+col);
                    if(row+1 < m && grid[row+1][col] == '1')   uf.Union(row*n+col, (row+1)*n+col);
                    if(col-1 >= 0 && grid[row][col-1] == '1')   uf.Union(row*n+col, row*n+col-1);
                    if(col+1 < n && grid[row][col+1] == '1')   uf.Union(row*n+col, row*n+col+1);
                }
            }
        }
        
        return uf.getCount();
    }
};