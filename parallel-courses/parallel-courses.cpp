class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n+1, 0);
        vector<vector<int>> graph(n+1);
        for(auto& relation : relations)
        {
            graph[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        
        int step = 0;
        int studiedCount = 0;
        vector<int> bfsQueue;
        for(int i=1; i<n+1; i++)
        {
            if(indegree[i] == 0)
                bfsQueue.push_back(i);
        }
        
        while(!bfsQueue.empty())
        {
            step++;
            vector<int> nextQueue;
            for(auto& node : bfsQueue)
            {
                studiedCount++;
                for(auto& endNode : graph[node])
                {
                    if(--indegree[endNode] == 0)
                        nextQueue.push_back(endNode);
                }
            }
            
            bfsQueue = nextQueue;
        }
        
        return studiedCount == n ? step : -1;
    }
};