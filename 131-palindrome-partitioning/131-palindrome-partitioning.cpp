class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> p;
        
        backtracking(s, 0, ans, p);
        return ans;
    }
    
    void backtracking(string s, int start, vector<vector<string>>& ans, vector<string>& p) {
        if(start == s.length()) {
            ans.push_back(p);
            return;
        }
        
        for(int i = start; i < s.length(); i++) {
            string str = s.substr(start, i - start + 1);
            if(isPalindrome(str)) {
                p.push_back(str);
                backtracking(s, i + 1, ans, p);
                p.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
};