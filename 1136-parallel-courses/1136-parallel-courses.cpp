class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> courses(n + 1);
        vector<int> indegree(n + 1, 0);
        queue<int> q;
        
        for(auto& relation : relations) {
            courses[relation[0]].push_back(relation[1]);
            ++indegree[relation[1]];
        }
        
        for(int i = 1; i < indegree.size(); i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0, visited = 0;
        while(!q.empty()) {
            count++;
            int n = q.size();
            while(n--) {
                int v = q.front();
                q.pop();
                
                visited++;
                for(auto c : courses[v]) {
                    if(--indegree[c] == 0)
                        q.push(c);
                }
            }
        }
        
        return visited == n ? count : -1;
    }
};