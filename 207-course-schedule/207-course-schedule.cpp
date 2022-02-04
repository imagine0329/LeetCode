class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, -1);
        unordered_map<int, vector<int>> courses;
        
        for(auto p : prerequisites)
            courses[p.back()].push_back(p.front());
        
        for(auto course : courses) {
            if(visited[course.first] == -1 && !dfs(courses, visited, course.first))
                return false;
        }
        
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>>& courses, vector<int>& visited, int v) {
        visited[v] = 0;
        for(auto u : courses[v]) {
            if(visited[u] == 0) return false;
            if(visited[u] == -1 && !dfs(courses, visited, u))
                return false;
        }
        visited[v] = 1;
        return true;
    }
};