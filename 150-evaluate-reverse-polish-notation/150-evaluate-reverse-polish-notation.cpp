class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(auto token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                int res = 0;
                
                if(token == "+")
                    res = x + y;
                else if(token == "-")
                    res = y - x;
                else if(token == "*")
                    res = x * y;
                else if(token == "/")
                    res = y / x;
                
                s.push(res);
            }
            else
                s.push(stoi(token));
        }
        
        return s.top();
    }
};