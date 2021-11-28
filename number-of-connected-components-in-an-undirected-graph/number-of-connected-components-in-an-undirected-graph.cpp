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
