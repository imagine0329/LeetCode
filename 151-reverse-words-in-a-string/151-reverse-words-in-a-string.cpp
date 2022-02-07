class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        stringstream ss(s);
        string str, ans;
        
        while(ss >> str) {
            reverse(str.begin(), str.end());
            ans += str + " ";
        }
        
        ans.pop_back();
        return ans;
    }
};