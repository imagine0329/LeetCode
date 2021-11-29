class Solution {
public:
    int find(vector<int>& parent, int vertex){
        if(parent[vertex] == vertex)
            return vertex;
        
        return parent[vertex] = find(parent, parent[vertex]);
    }
    
    int combine(vector<int>& parent, int& sum, vector<int>& connection){
        int v1 = find(parent, connection[0]);
        int v2 = find(parent, connection[1]);
        
        if(v1 == v2)
            return 0;
        
        if(v1 < v2)
            parent[v2] = v1;
        else
            parent[v1] = v2;
        
        sum += connection[2];
        
        return -1;
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        if(connections.size() < 1)
            return -1;
        
        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++)
            parent[i] = i;
            
        int sum = 0;
        int component = n;
        for(auto c : connections)
        {
            component += combine(parent, sum, c);
        }
        
        if(component != 1)
            return -1;
        
        return sum;
    }
};

// 1. sort by cost in the ascending
// 2. combine all vetices
//      1) start from begin to end of the sorted array
//      2) after combination, n-- so that we can count the number of components
// 3. check the number of components
//      1) if it is greater than 1, return false
//      2) if it is 1, return true
