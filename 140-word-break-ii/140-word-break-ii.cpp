class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        string str;
        
        backtracking(s, dict, ans, str, 0);
        
        return ans;
    }
    
    void backtracking(string& s, unordered_set<string>& dict, vector<string>& ans, string& str, int start) {
        if(start == s.length()) {
            ans.push_back(string(str.begin(), str.end() - 1));
            return;
        }
        
        for(int i = start; i < s.length(); i++) {
            string word = s.substr(start, i - start + 1);
            if(dict.find(word) != dict.end()) {
                int erasePoint = str.length();
                str += word + " ";
                backtracking(s, dict, ans, str, i + 1);
                str.erase(erasePoint, word.length() + 1);
            }
        }
    }
};