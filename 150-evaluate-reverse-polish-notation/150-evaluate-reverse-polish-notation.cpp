class Solution {
private:
    bool isNumber(const string& s) {
        int sign = s.length() > 1 && s[0] == '-' ? 1 : 0;
        return all_of(s.begin() + sign, s.end(), [](char c) {
            return isdigit(c);
        });
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(auto t : tokens) {
            if(isNumber(t)) s.push(stoi(t));
            else {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                if(t == "+") s.push(n1 + n2);
                else if(t == "-") s.push(n1 - n2);
                else if(t == "*") s.push(n1 * n2);
                else s.push(n1 / n2);
            }
        }
        
        return s.top();
    }
};