class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        vector<bool> visited(n, false);
        
        for(auto e : edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        
        if(dfs(0, -1, m, visited) == false)
            return false;
        
        for(auto v : visited) {
            if(v != 1)
                return false;
        }
        
        return true;
    }
    
    bool dfs(int n, int parent, unordered_map<int, vector<int>>& m, vector<bool>& visited) {
        if(visited[n])
            return false;
        
        visited[n] = true;
        for(auto adj : m[n]) {
            if(parent != adj && dfs(adj, n, m, visited) == false)
                return false;
        }
        
        return true;
    }
};
