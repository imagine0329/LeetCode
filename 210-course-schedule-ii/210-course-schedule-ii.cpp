class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;
        
        for(auto p : prerequisites) {
            m[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            auto n = q.front();
            q.pop();
            ans.push_back(n);
            
            for(auto v : m[n]) {
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
        
        if(ans.size() == numCourses)
            return ans;
        
        return vector<int>();
    }
};