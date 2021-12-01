class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        
        for(int i=0; i<ppid.size(); i++)
        {
            if(ppid[i] == 0)
                continue;
            
            m[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        ans.push_back(kill);
        
        dfs(ans, m, kill);
        
        return ans;
    }
    
    void dfs(vector<int>& ans, unordered_map<int, vector<int>>& m, int kill)
    {
        if(m.find(kill) == m.end())
            return;
        
        for(int i=0; i<m[kill].size(); i++)
        {
            ans.push_back(m[kill][i]);
            dfs(ans, m, m[kill][i]);
        }    
    }
};
