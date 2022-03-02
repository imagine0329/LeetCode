class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(n, false);
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        return dfs(graph, visited, source, destination);
    }
    
    bool dfs(unordered_map<int, vector<int>>& graph, vector<int>& visited, int s, int d) {
        if(s == d) return true;
        visited[s] = true;
        for(auto v : graph[s]) {
            if(!visited[v] && dfs(graph, visited, v, d))
                return true;
        }
        return false;
    }
};