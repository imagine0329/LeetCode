class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;
        for(int i = 0; i < s.length(); i++) {
            if(!dq.empty() && s[i] == dq.back())
                dq.pop_back();
            else
                dq.push_back(s[i]);
        }
        
        string ans = "";
        int n = dq.size();
        while(n--) {
            ans += dq.front();
            dq.pop_front();
        }
        
        return ans;
    }
};