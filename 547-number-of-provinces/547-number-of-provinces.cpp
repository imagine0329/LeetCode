class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for(int v = 0; v < n; v++) {
            if(visited[v] == false) {
                count++;
                dfs(isConnected, visited, v);
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int v) {
        visited[v] = true;
        for(int i = 0; i < isConnected.size(); i++) {
            if(isConnected[v][i] && visited[i] == false) {
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }
    }
};