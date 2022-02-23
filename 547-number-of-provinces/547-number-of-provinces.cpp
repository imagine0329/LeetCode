class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j])
                    graph[i].push_back(j);
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false) {
                count++;
                bfs(graph, visited, v);
            }
        }
        
        return count;
    }
    
    void bfs(vector<vector<int>>& graph, vector<bool>& visited, int v) {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                v = q.front(); q.pop();
                for(auto u : graph[v]) {
                    if(visited[u] == false) {
                        visited[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }
};