static bool compare(const string &s1, const string &s2) {
    return s1.length() < s2.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), compare);
        
        int longest = 0;
        for(const auto& word : words) {
            for(int i = 0; i < word.length(); i++) {
                string newWord = word.substr(0, i) + word.substr(i + 1);
                dp[word] = max(dp[word], dp.find(newWord) == dp.end() ? 1 : 1 + dp[newWord]);
            }
            
            longest = max(longest, dp[word]);
        }
            
        return longest;
    }
};