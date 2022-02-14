class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> seen;
        vector<vector<int>> graph(n);
        
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(seen.find(i) == seen.end()) {
                count++;
                dfs(graph, seen, i);
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& graph, unordered_set<int>& seen, int v) {
        seen.insert(v);
        for(auto u : graph[v]) {
            if(seen.find(u) == seen.end())
                dfs(graph, seen, u);
        }
    }
};