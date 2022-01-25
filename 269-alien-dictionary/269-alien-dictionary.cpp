class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        
        for(auto word : words) {
            for(auto c : word)
                indegree[c] = 0;
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.length(), word2.length());
            for(int j = 0; j < len; j++) {
                if(word1[j] != word2[j]) {
                    if(graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                        graph[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
                
                if(j == len - 1 && word1.length() > word2.length())
                    return "";
            }
        }
        
        string ans;
        queue<char> q;
        for(auto e : indegree) {
            if(e.second == 0)
                q.push(e.first);
        }
        
        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            ans += c;
            for(auto e : graph[c]) {
                if(--indegree[e] == 0)
                    q.push(e);
            }
        }
        
        return ans.length() == indegree.size() ? ans : "";
    }
};