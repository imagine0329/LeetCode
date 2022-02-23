class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        queue<int> q;
        vector<bool> visited(n, false);
        int count = 0;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false) {
                count++;
                q.push(v);
                while(!q.empty()) {
                    int u = q.front(); q.pop();
                    visited[u] = true;
                    for(int i = 0; i < n; i++) {
                        if(isConnected[u][i] && visited[i] == false)
                            q.push(i);
                    }
                }
            }
        }
        
        return count;
    }
};