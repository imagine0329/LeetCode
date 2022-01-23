class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    
public:
    UnionFind(int n) {
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1, 0);
        count = n;
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if(x != parent[x])
            return parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    bool Union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y)
            return false;
        
        if(rank[x] > rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else {
            parent[x] = y;
            rank[y] += rank[x];
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
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        
        UnionFind* uf = new UnionFind(n);
        int cost = 0;
        for(int i = 0; i < connections.size(); i++) {
            int x = connections[i][0], y = connections[i][1];
            if(uf->Union(x, y))
                cost += connections[i][2];
        }
        
        if(uf->getCount() == 1)
            return cost;
        else
            return -1;
    }
};













