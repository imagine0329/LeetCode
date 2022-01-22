class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto c : s) {
            if(c == ans.back())
                ans.pop_back();
            else
                ans.push_back(c);
        }
        
        return ans;
    }
};