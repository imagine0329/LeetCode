class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
        
        for(auto s : words) {
            for(auto c : s)
                indegree[c] = 0;
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            int p = 0;
            while(p < min(words[i].length(), words[i + 1].length())) {
                if(words[i].length() > words[i + 1].length() && words[i].substr(0, words[i + 1].length()) == words[i + 1])
                    return "";
                
                if(words[i][p] != words[i + 1][p]) {
                    graph[words[i][p]].push_back(words[i + 1][p]);
                    indegree[words[i + 1][p]]++;
                    break;
                }
                p++;
            }
        }
        
        queue<char> q;
        for(auto e : indegree) {
            if(e.second == 0)
                q.push(e.first);
        }
        
        string ans;
        while(!q.empty()) {
            char c = q.front(); q.pop();
            ans += c;
            for(auto next : graph[c]) {
                if(--indegree[next] == 0)
                    q.push(next);
            }
        }
        
        return ans.length() < indegree.size() ? "" : ans;
    }
};