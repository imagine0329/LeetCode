class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(n, false);
        queue<int> q;
        q.push(source);
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front(); q.pop();
                if(v == destination) return true;
                visited[v] = true;
                for(auto u : graph[v]) {
                    if(!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                    }
                }
            }
        }
        return false;
    }
};