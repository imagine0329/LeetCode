class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) 
                q.push(i);
        }
        
        if(q.empty()) return {};
        
        while(!q.empty()) {
            int v = q.front(); q.pop();
            ans.push_back(v);
            for(auto u : graph[v]) {
                if(--indegree[u] == 0)
                    q.push(u);
            }
        }
        
        return ans.size() == numCourses ? ans : vector<int>();
    }
};