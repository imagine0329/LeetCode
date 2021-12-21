class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int components;
    
public:
    UnionFind(vector<vector<char>>& grid){
        components = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1')
                {
                    parent.push_back((i * n) + j);
                    components++;
                }
                else
                    parent.push_back(-1);
                
                rank.push_back(0);
            }
        }
    }
    
    int find(int i)
    {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        
        if(x == y)
            return;
        
        if(rank[x] > rank[y])
            parent[y] = x;
        else if(rank[x] < rank[y])
            parent[x] = y;
        else
        {
            parent[y] = x;
            rank[x]++;
        }
        
        --components;
    }
    
    int getNumOfComponents()
    {
        return components;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        UnionFind uf(grid);
        int m = grid.size();
        int n = grid[0].size();
        
        for(int row=0; row<m; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col] == '1')
                {
                    grid[row][col] = '0';
                    if(row-1 >= 0 && grid[row-1][col] == '1')   uf.Union(row*n+col, (row-1)*n+col);
                    if(row+1 < m && grid[row+1][col] == '1')    uf.Union(row*n+col, (row+1)*n+col);
                    if(col-1 >= 0 && grid[row][col-1] == '1')    uf.Union(row*n+col, row*n+(col-1));
                    if(col+1 < n && grid[row][col+1] == '1')    uf.Union(row*n+col, row*n+(col+1));
                }
            }
        }
        
        return uf.getNumOfComponents();
    }
};