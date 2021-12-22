class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        
        backtracking(ans, str, 0, 0, n);
        
        return ans;
    }
    
    void backtracking(vector<string>& ans, string& str, int left, int right, int n)
    {
        if(str.length() == 2*n)
        {
            ans.push_back(str);
            return;
        }
        
        if(left < n)
        {
            str += '(';
            backtracking(ans, str, left+1, right, n);
            str.pop_back();
        }
        
        if(right < n && left > right)
        {
            str += ')';
            backtracking(ans, str, left, right+1, n);
            str.pop_back();
        }
    }
};