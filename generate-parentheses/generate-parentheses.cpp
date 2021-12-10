class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        
        backtracking(ans, str, n, 0, 0);
        
        return ans;
    }
    
    void backtracking(vector<string>& ans, string& str, int n, int open, int close)
    {
        if(str.length() == n*2)
        {
            ans.push_back(str);
            return;
        }
        
        if(open < n)
        {
            str += "(";
            backtracking(ans, str, n, open+1, close);
            str.pop_back();
        }
        
        if(close < open)
        {
            str += ")";
            backtracking(ans, str, n, open, close+1);
            str.pop_back();
        }
    }
};