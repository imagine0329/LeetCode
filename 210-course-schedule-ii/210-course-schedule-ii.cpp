class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> visited(numCourses, -1);
        vector<int> ans;
        
        for(auto pre : prerequisites)
            m[pre[1]].push_back(pre[0]);
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == -1) {
                if(dfs(m, visited, ans, i) == false)
                    return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool dfs(unordered_map<int, vector<int>>& m, vector<int>& visited, vector<int>& ans, int v) {
        visited[v] = 0;
        
        for(auto u : m[v]) {
            if(visited[u] == 0)
                return false;
            if(visited[u] == -1 && dfs(m, visited, ans, u) == false)
                return false;
        }
        ans.push_back(v);
        visited[v] = 1;
        return true;
    }
};