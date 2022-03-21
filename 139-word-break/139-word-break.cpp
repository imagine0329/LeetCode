class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.length(), false);
        
        q.push(0);
        while(!q.empty()) {
            int start = q.front(); q.pop();
            if(visited[start]) continue;
            for(int end = start + 1; end <= s.length(); end++) {
                if(dict.find(s.substr(start, end - start)) != dict.end()) {
                    q.push(end);
                    if(end == s.length()) return true;
                }
            }
            visited[start] = true;
        }
        return false;
    }
};