class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        unordered_map<string, bool> memo;
        for(auto word : words) {
            if(isConcatenate(dict, word, memo))
                ans.push_back(word);
        }
        
        return ans;
    }
    
    bool isConcatenate(unordered_set<string>& dict, string word, unordered_map<string, bool>& memo) {
        if(memo.find(word) != memo.end())
            return memo[word];
        
        for(int len = 1; len < word.length(); len++) {
            if(dict.find(word.substr(0, len)) != dict.end()) {
                string s = word.substr(len);
                if(dict.find(s) != dict.end() || isConcatenate(dict, s, memo))
                    return memo[word] = true;
            }
        }
        return memo[word] = false;
    }
};