class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
    
    string buildString(string str) {
        stack<char> s;
        for(auto c : str) {
            if(c != '#')
                s.push(c);
            else if(!s.empty())
                s.pop();
        }
        
        string ret;
        while(!s.empty()) {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
};