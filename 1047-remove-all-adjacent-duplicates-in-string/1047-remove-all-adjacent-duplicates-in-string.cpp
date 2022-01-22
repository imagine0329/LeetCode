class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;
        for(int i = 0; i < s.length(); i++) {
            while(!dq.empty() && s[i] == dq.back()){
                dq.pop_back();
                i++;
            }
            
            if(i < s.length())
                dq.push_back(s[i]);
        }
        
        string ans = "";
        int n = dq.size();
        for(int i = 0; i < n; i++) {
            ans += dq.front();
            dq.pop_front();
        }
        
        return ans;
    }
};