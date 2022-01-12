class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> visited(numCourses, -1);
        
        for(auto p : prerequisites)
            m[p[1]].push_back(p[0]);
        
        for(int curr=0; curr<numCourses; curr++) {
            if(isCyclic(curr, m, visited))
                return false;
        }
        
        return true;
    }
    
    bool isCyclic(int curr, unordered_map<int, vector<int>>& m, vector<int>& visited)
    {
        if(visited[curr] == 1)
            return false;
        else if(visited[curr] == 0)
            return true;
        
        if(m.find(curr) == m.end())
            return false;
        
        visited[curr] = 0;
        for(int i=0; i<m[curr].size(); i++)
        {
            if(isCyclic(m[curr][i], m, visited))
                return true;
        }
        
        visited[curr] = 1;
        return false;
    }
};