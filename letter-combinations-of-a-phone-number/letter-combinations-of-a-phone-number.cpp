class Solution {
private:
    unordered_map<char, string> m{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                 {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                 {'8', "tuv"}, {'9', "wxyz"}};
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string str;
        
        if(digits.length() > 0)
            backtracking(digits, ans, str, 0);
        
        return ans;
    }
    
    void backtracking(string digits, vector<string>& ans, string& str, int i)
    {
        if(i == digits.length())
        {
            ans.push_back(str);
            return;
        }
        
        for(int j=0; j<m[digits[i]].size(); j++)
        {
            str += m[digits[i]][j];
            backtracking(digits, ans, str, i+1);
            str.pop_back();
        }
    }
};