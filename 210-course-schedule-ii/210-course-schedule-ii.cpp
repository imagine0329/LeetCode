/*
return
    - order of courses I should take to finish all courses
        if many valid answers -> return any of them
    - impossible to finish all courses -> return an empty array
    
    
*/


//  visited status
//  -1 = not yet, 0 = visiting, 1 = visited
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(numCourses, -1);
        vector<int> ans;
        
        for(auto pre : prerequisites)
            graph[pre[1]].push_back(pre[0]);
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == -1) {
                if(dfs(graph, visited, i, ans) == false)
                    return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
            
        return ans;
    }
    
    bool dfs(unordered_map<int, vector<int>>& graph, vector<int>& visited, int v, vector<int>& ans) {
        if(visited[v] == 0)
            return false;
        
        visited[v] = 0;
        
        for(auto u : graph[v]) {
            if(visited[u] != 1) {
                if(dfs(graph, visited, u, ans) == false)
                    return false;
            }
        }
        
        ans.push_back(v);
        visited[v] = 1;
        return true;
    }
};