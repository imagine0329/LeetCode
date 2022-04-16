class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;
        
        for(auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        for(int v = 0; v < numCourses; v++) {
            if(indegree[v] == 0)
                q.push(v);
        }
        
        if(q.empty())
            return {};
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int v = q.front();
                q.pop();
                ans.push_back(v);
                for(auto u : graph[v]) {
                    if(--indegree[u] == 0)
                        q.push(u);
                }
            }
        }
        
        return ans.size() == numCourses ? ans : vector<int>();
    }
};