class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() < n - 1) return false;
        
        vector<unordered_set<int>> graph(n);
        queue<int> q;
        vector<bool> visited(n, false);
        
        for(auto& e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        q.push(0);
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            if(visited[v]) return false;
            visited[v] = true;
            n--;
            for(auto u : graph[v]) {
                q.push(u);
                graph[u].erase(v);
            }
        }
        
        return n == 0;
    }
};


