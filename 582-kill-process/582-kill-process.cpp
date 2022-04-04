class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < pid.size(); i++)
            graph[ppid[i]].push_back(pid[i]);
        
        queue<int> q;
        vector<int> ans;
        
        q.push(kill);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                kill = q.front(); q.pop();
                ans.push_back(kill);
                for(auto e : graph[kill])
                    q.push(e);
            }
        }
        
        return ans;
    }
};