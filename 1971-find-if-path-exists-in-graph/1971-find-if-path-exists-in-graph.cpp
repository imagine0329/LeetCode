class Solution {
private:
    vector<int> parent, rank;

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        for(auto e : edges) {
            int x = find(e[0]), y = find(e[1]);
            if(x != y) {
                if(rank[x] >= rank[y]) {
                    parent[y] = x;
                    rank[x]++;
                }
                else {
                    parent[x] = y;
                    rank[y]++;
                }
            }
        }
        
        return find(source) == find(destination);
    }
    
    int find(int x) {
        if(parent[x] != x)
            return parent[x] = find(parent[x]);
        return x;
    }
};