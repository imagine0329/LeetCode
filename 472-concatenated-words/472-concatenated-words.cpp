class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        unordered_map<string, bool> memo;
        vector<string> ans;
        for(auto word : words) {
            if(dfs(word, dict, memo)) ans.push_back(word);
        }
        return ans;
    }
    
    bool dfs(string word, unordered_set<string>& dict, unordered_map<string, bool>& memo) {
        if(memo.find(word) != memo.end()) return memo[word];
        
        for(int i = 1; i < word.length(); i++) {
            string substring = word.substr(0, i);
            if(dict.find(substring) != dict.end()) {
                string restSubstring = word.substr(i);
                if(dict.find(restSubstring) != dict.end() || dfs(restSubstring, dict, memo)) {
                    memo[word] = true;
                    return true;
                }
            }
        }
        
        memo[word] = false;
        return false;
    }
};