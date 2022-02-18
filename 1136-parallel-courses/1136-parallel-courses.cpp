class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        
        for(auto r : relations) {
            graph[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        
        queue<int> q;
        for(int i = 1; i < n + 1; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        if(q.size() == 0)
            return -1;
        
        int step = 0, course = 0;
        while(!q.empty()) {
            int sz = q.size();
            course += sz;
            while(sz--) {
                int v = q.front(); q.pop();
                for(auto u : graph[v]) {
                    if(--indegree[u] == 0)
                        q.push(u);
                }
            }
            step++;
        }
        
        return course == n ? step : -1;
    }
};