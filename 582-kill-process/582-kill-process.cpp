class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < pid.size(); i++)
            graph[ppid[i]].push_back(pid[i]);
        
        vector<int> ans;
        ans.push_back(kill);
        dfs(ans, graph, kill);
        return ans;
    }
    
    void dfs(vector<int>& ans, unordered_map<int, vector<int>>& graph, int kill) {
        if(graph.find(kill) != graph.end()) {
            for(auto e : graph[kill]) {
                ans.push_back(e);
                dfs(ans, graph, e);
            }
        }
    }
};