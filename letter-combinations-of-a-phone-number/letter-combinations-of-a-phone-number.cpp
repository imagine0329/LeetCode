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
            backtracking(ans, str, digits, 0);
        
        return ans;
    }
    
    void backtracking(vector<string>& ans, string& str, string digits, int i)
    {
        if(str.length() == digits.length())
        {
            ans.push_back(str);
            return;
        }
        
        for(int k = 0; k<m[digits[i]].length(); k++)
        {
            str += m[digits[i]][k];
            backtracking(ans, str, digits, i+1);
            str.pop_back();
        }
    }
};