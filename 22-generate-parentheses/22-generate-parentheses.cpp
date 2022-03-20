class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        
        backtracking(ans, str, n, n);
        return ans;
    }
    
    void backtracking(vector<string>& ans, string& str, int left, int right) {
        if(left == 0 && right == 0) {
            ans.push_back(str);
            return;
        }
        
        if(left > 0) {
            str += '(';
            backtracking(ans, str, left - 1, right);
            str.pop_back();
        }
        if(left < right && right > 0) {
            str += ')';
            backtracking(ans, str, left, right - 1);
            str.pop_back();
        }
    }
};