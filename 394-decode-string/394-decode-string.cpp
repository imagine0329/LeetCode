class Solution {
public:
    string decodeString(string str) {
        stack<char> s;
        
        for(auto c : str) {
            if(c != ']')
                s.push(c);
            else {
                string temp;
                while(!s.empty() && s.top() != '[') {
                    temp += s.top(); s.pop();
                }
                
                s.pop();
                string sn;
                while(!s.empty() && isdigit(s.top())) {
                    sn += s.top(); s.pop();
                }
                reverse(sn.begin(), sn.end());
                int n = stoi(sn);
                while(n--) {
                    for(int i = temp.size() - 1; i >= 0; i--)
                        s.push(temp[i]);
                }
            }
        }
        
        string ans;
        while(!s.empty()) {
            ans += s.top(); s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};