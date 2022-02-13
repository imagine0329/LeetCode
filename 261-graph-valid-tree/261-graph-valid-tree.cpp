class UnionFind {
private:
    vector<int> parent, rank;
    int count;
    
public:
    UnionFind(int n) {
        count = n;
        parent = vector<int>(n);
        rank = vector<int>(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int n) {
        if(parent[n] != n)
            return parent[n] = find(parent[n]);
        return n;
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
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        for(auto e : edges) {
            if(uf.Union(e[0], e[1]) == false)
                return false;
        }
        
        return uf.getCount() == 1;
    }
};


