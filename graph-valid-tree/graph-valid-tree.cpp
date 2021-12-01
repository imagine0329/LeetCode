/*  DFS*/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;
        
        vector<vector<int>> adj(n);
        for(auto e : edges)
        {
            adj[e.front()].push_back(e.back());
            adj[e.back()].push_back(e.front());
        }
        
        unordered_map<int, int> parent;
        parent[0] = -1;
        stack<int> s;
        s.push(0);
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            for(auto neighbour : adj[node])
            {
                if(parent[node] == neighbour)
                    continue;
                
                if(parent.find(neighbour) != parent.end())
                    return false;
                
                s.push(neighbour);
                parent[neighbour] = node;
            }
        }
        
        return parent.size() == n;
    }
};

/*  Union Find
class Solution {
public:
    int find(vector<int>& parent, int node)
    {
        if(parent[node] == node)
            return node;
        
        return parent[node] = find(parent, parent[node]);
    }
    
    bool combine(vector<int>& parent, int n1, int n2)
    {
        n1 = find(parent, n1);
        n2 = find(parent, n2);
        
        if(n1 == n2)
            return false;
        
        if(n1 < n2)
            parent[n2] = n1;
        else
            parent[n1] = n2;
        
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
            return false;
        
        vector<int> parent(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        for(auto e : edges)
        {
            if(combine(parent, e.front(), e.back()) == false)
                return false;
        }
        
        return true;
    }
};*/