class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length(), false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int start = q.front(); q.pop();
            if(visited[start])
                continue;
            visited[start] = true;
            for(int i = start + 1; i <= s.length(); i++) {
                string str = s.substr(start, i - start);
                if(dict.find(str) != dict.end()) {
                    if(i == s.length()) return true;
                    q.push(i);
                }
            }
        }
        
        return false;
    }
};