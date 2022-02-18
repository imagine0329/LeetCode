class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, 0);
        
        for(auto& r : relations)
            graph[r[0]].push_back(r[1]);
        
        int longest = 1;
        for(int i = 1; i <= n; i++) {
            int path = dfs(graph, visited, i);
            if(path == -1) return -1;
            longest = max(longest, path);
        }
        
        return longest;
    }
    
    int dfs(vector<vector<int>>& graph, vector<int>& visited, int i) {
        if(visited[i] != 0) return visited[i];
        visited[i] = -1;
        int longest = 1;
        for(auto v : graph[i]) {
            int path = dfs(graph, visited, v);
            if(path == -1) return -1;
            longest = max(longest, path + 1);
        }
        visited[i] = longest;
        return longest;
    }
};