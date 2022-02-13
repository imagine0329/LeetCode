class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        if(!dfs(graph, visited, 0, -1))
            return false;
        
        for(auto v : visited) {
            if(!v) return false;
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int v, int parent) {
        if(visited[v])
            return false;
        
        visited[v] = true;
        for(auto u : graph[v]) {
            if(parent != u && !dfs(graph, visited, u, v))
                return false;
        }
        return true;
    }
};


