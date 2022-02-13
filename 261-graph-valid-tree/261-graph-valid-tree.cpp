class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        for(auto& e : edges) {
            int x = find(e[0], parent), y = find(e[1], parent);
            if(x == y) return false;
            
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
        
        return n == 1;
    }
    
    int find(int x, vector<int>& parent) {
        if(parent[x] != x)
            return parent[x] = find(parent[x], parent);
        return x;
    }
};


