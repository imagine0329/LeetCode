class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> m;
        unordered_set<string> seen;
        queue<string> q;
        
        for(auto s : wordList) {
            for(int i = 0; i < s.length(); i++) {
                string str = s;
                str[i] = '*';
                m[str].push_back(s);
            }
        }
        
        q.push(beginWord);
        seen.insert(beginWord);
        int step = 0;
        
        while(!q.empty()) {
            step++;
            int n = q.size();
            while(n--) {
                string word = q.front(); q.pop();
                if(word == endWord)
                    return step;
                
                for(int i = 0; i < word.length(); i++) {
                    string s = word;
                    s[i] = '*';
                    for(auto e : m[s]) {
                        if(seen.find(e) == seen.end()) {
                            q.push(e);
                            seen.insert(e);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};