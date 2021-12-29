class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> visited(numCourses, -1);
        
        for(auto pre : prerequisites)
            v[pre[1]].push_back(pre[0]);
        
        for(int i=0; i<numCourses; i++)
        {
            if(visited[i] == -1 && !backtracking(v, visited, i))
                return false;
        }
        
        return true;
    }
               
    bool backtracking(vector<vector<int>>& v, vector<int>& visited, int i)
    {
        if(visited[i] == 0)
            return false;
        
        if(visited[i] == 1)
            return true;
        
        visited[i] = 0;
        for(int j=0; j<v[i].size(); j++)
        {
            if(!backtracking(v, visited, v[i][j]))
                return false;
        }
        visited[i] = 1;
        
        return true;
    }    
};