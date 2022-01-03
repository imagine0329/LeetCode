class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        
        backtracking(ans, str, n, 0, 0);
        
        return ans;
    }
    
    void backtracking(vector<string>& ans, string& str, int n, int left, int right)
    {
        if(str.length() == n*2)
        {
            ans.push_back(str);
            return;
        }
        
        if(left < n)
        {
            str += '(';
            backtracking(ans, str, n, left+1, right);
            str.pop_back();
        }
        
        if(right < left)
        {
            str += ')';
            backtracking(ans, str, n, left, right+1);
            str.pop_back();
        }
    }
};