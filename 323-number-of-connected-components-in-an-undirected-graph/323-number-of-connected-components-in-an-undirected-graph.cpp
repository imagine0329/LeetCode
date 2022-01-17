class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                count++;
                dfs(graph, visited, i);
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i) {
        if(visited[i])
            return;
        
        visited[i] = true;
        
        for(int j = 0; j < graph[i].size(); j++) {
            if(visited[graph[i][j]] == false)
                dfs(graph, visited, graph[i][j]);
        }
    }
};

