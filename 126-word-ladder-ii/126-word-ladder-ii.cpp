class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> m;
        unordered_set<string> seen;
        int shortest = INT_MAX;
        
        for(auto s : wordList) {
            for(int i = 0; i < s.length(); i++) {
                string str = s;
                str[i] = '*';
                m[str].push_back(s);
            }
        }
        
        vector<vector<string>> ans;
        vector<string> prev;
        queue<vector<string>> q;
        
        q.push({beginWord});
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto v = q.front(); q.pop();
                if(v.size() > shortest) continue;
                string word = v.back();
                seen.insert(word);
                
                if(word == endWord && v.size() <= shortest) {
                    ans.push_back(v);
                    shortest = v.size();
                    continue;
                }
                
                for(int i = 0; i < word.length(); i++) {
                    string str = word;
                    str[i] = '*';
                    for(auto s : m[str]) {
                        if(seen.find(s) == seen.end()) {
                            v.push_back(s);
                            q.push(v);
                            v.pop_back();
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};