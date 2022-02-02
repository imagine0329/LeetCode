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
            for(int end = start + 1; end <= s.length(); end++) {
                if(dict.find(s.substr(start, end - start)) != dict.end()) {
                    if(end == s.length())
                        return true;
                    q.push(end);
                }
            }
        }
        
        return false;
    }
};