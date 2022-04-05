class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> visited(numCourses, -1);
        vector<vector<int>> graph(numCourses);
        
        for(auto pre : prerequisites)
            graph[pre[1]].push_back(pre[0]);
        
        for(int i = 0 ; i < numCourses; i++) {
            if(visited[i] != 1 && !dfs(graph, i, visited, ans))
                return {};
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    bool dfs(vector<vector<int>>& graph, int v, vector<int>& visited, vector<int>& ans) {
        if(visited[v] == 0) return false;
        visited[v] = 0;
        
        for(auto u : graph[v]) {
            if(visited[u] != 1 && !dfs(graph, u, visited, ans))
                return false;
        }
        ans.push_back(v);
        visited[v] = 1;
        return true;
    }
};