class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> courses;
        queue<int> q;
        int edges = prerequisites.size();
        
        for(auto p : prerequisites) {
            courses[p.back()].push_back(p.front());
            indegree[p.front()]++;
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for(auto u : courses[v]) {
                edges--;
                if(--indegree[u] == 0)
                    q.push(u);
            }
        }
        
        return edges == 0;
    }
};