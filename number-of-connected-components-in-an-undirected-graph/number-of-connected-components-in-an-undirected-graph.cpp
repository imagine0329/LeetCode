class Solution {
public:
    int find(vector<int>& parent, int vertex){
        if(parent[vertex] == vertex)
            return vertex;
        
        int root = parent[vertex];
        while(parent[root] != root)
            root = parent[root];
        
        while(parent[vertex] != root)
        {
            int next = parent[vertex];
            parent[vertex] = root;
            vertex = next;
        }
        
        return root;
    }
    
    int combine(vector<int>& parent, int v1, int v2){
        v1 = find(parent, v1);
        v2 = find(parent, v2);
        
        if(v1 == v2)
            return 0;
        
        if(v1 < v2)
            parent[v2] = v1;
        else
            parent[v1] = v2;
        
        return -1;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        int ans = n;
        for(int i=0; i<edges.size(); i++)
            ans += combine(parent, edges[i][0], edges[i][1]);
        
        return ans;
    }
};



/*  DFS
class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& visited, int src){
        visited[src] = 1;
        
        for(int i=0; i<adj[src].size(); i++)
        {
            if(visited[adj[src][i]] == 0)
                dfs(adj, visited, adj[src][i]);
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        vector<int> adj[n];
        
        for(auto edge : edges)
        {
            adj[edge.front()].push_back(edge.back());
            adj[edge.back()].push_back(edge.front());
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                ans++;
                dfs(adj, visited, i);
            }
        }
        
        return ans;
    }
};*/

/*  Union Find
class Solution {
public:
    int find(vector<int>& parent, int vertex){
        if(parent[vertex] == vertex)
            return vertex;
        
        int root = parent[vertex];
        while(parent[root] != root)
        {
            root = parent[root];
            parent[vertex] = root;
        }    
        
        return root;
    }
    
    int combine(vector<int>& parent, int v1, int v2){
        v1 = find(parent, v1);
        v2 = find(parent, v2);
        
        if(v1 == v2)
            return 0;
        
        if(v1 < v2)
            parent[v2] = v1;
        else
            parent[v1] = v2;
        
        return -1;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent;
        
        for(int i=0; i<n; i++)
            parent.push_back(i);
        
        int ans = n;
        
        for(auto edge : edges)
            ans += combine(parent, edge.front(), edge.back());
        
        return ans;
    }
};
*/