class Solution {
private:
    unordered_map<char, vector<char>> m = { {'2', {'a', 'b', 'c'}},
                                            {'3', {'d', 'e', 'f'}},
                                            {'4', {'g', 'h', 'i'}},
                                            {'5', {'j', 'k', 'l'}},
                                            {'6', {'m', 'n', 'o'}},
                                            {'7', {'p', 'q', 'r', 's'}},
                                            {'8', {'t', 'u', 'v'}},
                                            {'9', {'w', 'x', 'y', 'z'}},
                                          };
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string str;
        
        if(digits.length() > 0)
            backtracking(ans, str, digits, 0);
        
        return ans;
    }
    
    void backtracking(vector<string>& ans, string& str, string digits, int idx)
    {
        if(str.length() == digits.length())
        {
            ans.push_back(str);
            return;
        }
        
        for(int i=0; i<m[digits[idx]].size(); i++)
        {
            str += m[digits[idx]][i];
            backtracking(ans, str, digits, idx+1);
            str.pop_back();
        }
    }
};