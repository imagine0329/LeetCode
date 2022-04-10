class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> ans;
        
        for(auto word : words) {
            if(isConcatenate(dict, word))
                ans.push_back(word);
        }
        
        return ans;
    }
    
    bool isConcatenate(unordered_set<string>& dict, string word) {
        for(int len = 1; len < word.length(); len++) {
            if(dict.find(word.substr(0, len)) != dict.end()) {
                if(dict.find(word.substr(len)) != dict.end())
                    return true;
                else if(isConcatenate(dict, word.substr(len)))
                    return true;
            }
        }
        return false;
    }
};