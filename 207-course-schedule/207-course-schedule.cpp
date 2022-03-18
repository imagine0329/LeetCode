class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        
        for(auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for(auto e : graph[v]) {
                if(--indegree[e] == 0)
                    q.push(e);
            }
        }
        
        for(auto v : indegree) {
            if(v != 0) return false;
        }
        return true;
    }
};