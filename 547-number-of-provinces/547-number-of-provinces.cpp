class UnionFind {
private:
    vector<int> parent, rank;
    int count;
    
public:
    UnionFind(int n) {
        count = n;
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        rank = vector<int>(n, 0);
    }
    
    int find(int x) {
        if(parent[x] != x)
            return parent[x] = find(parent[x]);
        return x;
    }
    
    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y) return;
        
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1)
                    uf.Union(i, j);
            }
        }
        
        return uf.getCount();
    }
};

