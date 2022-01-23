class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> courses;
        vector<int> visited(n + 1, 0);
        
        for(auto& relation : relations)
            courses[relation[0]].push_back(relation[1]);
        
        int count = 1;
        for(int v = 1; v <= n; v++) {
            int length = dfs(courses, visited, v);
            if(length == -1)
                return -1;
            count = max(count, length);
        }
        
        return count;
    }
    
    int dfs(unordered_map<int, vector<int>>& courses, vector<int>& visited, int v) {
        if(visited[v] != 0)
            return visited[v];
        else
            visited[v] = -1;
        
        int count = 1;
        for(int i = 0; i < courses[v].size(); i++) {
            int length = dfs(courses, visited, courses[v][i]);
            if(length == -1)
                return -1;
            count = max(count, length + 1);
        }
        
        return visited[v] = count;
    }
};