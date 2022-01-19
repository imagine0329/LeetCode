class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i < ppid.size(); i++)
            m[ppid[i]].push_back(pid[i]);
        
        q.push(kill);
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for(auto k : m[n])
                q.push(k);
        }
        
        return ans;
    }
};