class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    UnionFind(int n){
        parent = vector<int>(n);
        rank = vector<int>(n);
        count = n;
        
        for(int i=0; i<n; i++) {
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
        int xp = find(x);
        int yp = find(y);
        
        if(xp == yp)
            return false;
        
        if(rank[xp] >= rank[yp]) {
            parent[yp] = xp;
            rank[xp]++;
        }
        else {
            parent[xp] = yp;
            rank[yp]++;
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
