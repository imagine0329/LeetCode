class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> m;
        unordered_set<string> seen;
        
        for(auto s : wordList) {
            for(int i = 0; i < s.length(); i++) {
                string str = s;
                str[i] = '*';
                m[str].push_back(s);
            }
        }
        
        queue<string> q;
        int step = 0;
        
        q.push(beginWord);
        seen.insert(beginWord);
        
        while(!q.empty()) {
            step++;
            int n = q.size();
            while(n--) {
                string str = q.front(); q.pop();
                if(str == endWord) return step;
                for(auto& c : str) {
                    char org = c;
                    c = '*';
                    if(m.find(str) != m.end()) {
                        for(auto s : m[str]) {
                            q.push(s);
                            seen.insert(s);
                        }
                        m.erase(str);
                    }
                    c = org;
                }
            }
        }
        
        return 0;
    }
};