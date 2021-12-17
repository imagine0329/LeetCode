class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(auto c : str)
        {
            if(c == '(' || c == '[' || c == '{')
                s.push(c);
            else
            {
                if( s.empty() ||
                    s.top() != '(' && c == ')' ||
                    s.top() != '[' && c == ']' ||
                    s.top() != '{' && c == '}')
                    return false;
                
                s.pop();
            }
        }
        
        return s.empty();
    }
};