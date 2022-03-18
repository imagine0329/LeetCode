class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, -1);
        
        for(auto& p : prerequisites)
            graph[p[1]].push_back(p[0]);
        
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(graph, visited, i))
                return false;
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int v) {
        if(visited[v] == 0) return false;
        
        visited[v] = 0;
        for(int i = 0; i < graph[v].size(); i++) {
            if(visited[graph[v][i]] != 1) {
                if(!dfs(graph, visited, graph[v][i]))
                    return false;
            }
        }
        visited[v] = 1;
        return true;
    }
};