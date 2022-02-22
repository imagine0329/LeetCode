class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        unordered_set<string> s;
        
        for(const auto& word : words)
            s.insert(word);
        
        int longest = 0;
        for(const auto& word : words)
            longest = max(longest, dfs(s, memo, word));
        return longest;
    }
    
    int dfs(unordered_set<string>& words, unordered_map<string, int>& memo, string word) {
        if(memo.find(word) != memo.end()) return memo[word];
        
        int longest = 1;
        for(int i = 0; i < word.length(); i++) {
            string newWord = word.substr(0, i) + word.substr(i + 1);
            if(words.find(newWord) != words.end())
                longest = max(longest, 1 + dfs(words, memo, newWord));
        }
        
        return memo[word] = longest;
    }
};