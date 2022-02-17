struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        
        vector<int> parent(n + 1), rank(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
        
        sort(connections.begin(), connections.end(), Compare());
        int cost = 0;
        for(auto c : connections) {
            int x = find(parent, c[0]), y = find(parent, c[1]);
            if(x == y)
                continue;
            
            cost += c[2];
            if(rank[x] >= rank[y]) {
                parent[y] = x;
                rank[x]++;
            }
            else {
                parent[x] = y;
                rank[y]++;
            }
            
            n--;
        }
        
        return n == 1 ? cost : -1;
    }
    
    int find(vector<int>& parent, int x) {
        int root = parent[x];
        while(x != root) {
            parent[x] = parent[root];
            x = root;
            root = parent[x];
        }
        return x;
    }
};