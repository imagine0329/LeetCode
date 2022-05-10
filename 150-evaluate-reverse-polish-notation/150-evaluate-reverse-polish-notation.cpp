class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans = 0;
        
        for(auto token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int x = s.top(); s.pop();
                int y = s.top(); s.pop();
                int res;
                
                if(token == "+")
                    res = x + y;
                else if(token == "-")
                    res = y - x;
                else if(token == "*")
                    res = x * y;
                else
                    res = y / x;
                
                s.push(res);
            }
            else
                s.push(stoi(token));
        }
        
        return s.top();
    }
};

/*
["4","13","5","/","+"]

bottom          top
--------------------
4   2
--------------------
*/