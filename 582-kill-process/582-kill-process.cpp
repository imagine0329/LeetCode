class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < ppid.size(); i++)
            m[ppid[i]].push_back(pid[i]);
        
        vector<int> ans;
        vector<bool> visited(pid.size(), false);
        dfs(m, ans, visited, kill);
        
        return ans;
    }
    
    void dfs(unordered_map<int, vector<int>>& m, vector<int>& ans, vector<bool>& visited, int kill) {
        
        visited[kill] = true;
        ans.push_back(kill);
        for(int i = 0; i < m[kill].size(); i++) {
            if(visited[m[kill][i]] == false) 
                dfs(m, ans, visited, m[kill][i]);
        }
    }
};