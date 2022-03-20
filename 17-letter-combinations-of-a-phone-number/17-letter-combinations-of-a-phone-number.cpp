class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        
        vector<string> ans;
        string str;
        if(digits.length() > 0)
            backtracking(digits, 0, m, ans, str);
        return ans;
    }
    
    void backtracking(string& digits, int i, unordered_map<char, string>& m, vector<string>& ans, string& str) {
        if(str.length() == digits.length()) {
            ans.push_back(str);
            return;
        }
        
        for(auto c : m[digits[i]]) {
            str += c;
            backtracking(digits, i + 1, m, ans, str);
            str.pop_back();
        }
    }
    
};