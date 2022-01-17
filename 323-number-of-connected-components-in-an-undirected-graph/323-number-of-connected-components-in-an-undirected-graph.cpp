class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        count = n;
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int n) {
        if(parent[n] != n)
            return parent[n] = find(parent[n]);
        
        return n;
    }
    
    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y)
            return;
        
        if(rank[x] > rank[y]){
            parent[y] = x;
            rank[x]++;
        }
        else{
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        for(auto e : edges)
            uf.Union(e[0], e[1]);
        
        return uf.getCount();
    }
};

