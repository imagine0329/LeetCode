
/* BFS - Kahn's algorithm
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
};*/

/*  DFS - Check for Cycles + Find Longest Path*/
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n+1);
        for(auto& r : relations)
            graph[r[0]].push_back(r[1]);
        
        vector<int> visited(n+1, 0);
        for(int i=1; i<n+1; i++)
        {
            if(dfsCheckCycle(i, graph, visited) == -1)
                return -1;
        }
        
        vector<int> visitedLength(n+1, 0);
        int maxLength = 1;
        for(int i = 1; i<n+1; i++)
        {
            int len = dfsMaxPath(i, graph, visitedLength);
            maxLength = max(len, maxLength);
        }
        
        return maxLength;
    }
    
private:
    int dfsCheckCycle(int node, vector<vector<int>>& graph, vector<int>& visited)
    {
        if(visited[node] != 0)
            return visited[node];
        else
            visited[node] = -1;
        
        for(auto& endNode : graph[node])
        {
            if(dfsCheckCycle(endNode, graph, visited) == -1)
                return -1;
        }
        
        visited[node] = 1;
        return 1;
    }
    
    int dfsMaxPath(int node, vector<vector<int>>& graph, vector<int>& visitedLength)
    {
        if(visitedLength[node] != 0)
            return visitedLength[node];
        
        int maxLen = 1;
        for(auto& endNode : graph[node])
        {
            int len = dfsMaxPath(endNode, graph, visitedLength);
            maxLen = max(len + 1, maxLen);
        }
        
        visitedLength[node] = maxLen;
        return maxLen;
    }
};