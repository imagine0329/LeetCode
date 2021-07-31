class Solution {
public:
    bool isValid(string s) {
        stack<char> contain;
        int i=0;
        
        while(i<s.length())
        {
            char ch = s.at(i++);
            switch(ch)
            {
                case '(':
                case '{':
                case '[':
                    contain.push(ch);
                    break;
                    
                case ')':
                    if(contain.empty() || contain.top() != '(')
                        return false;
                    
                    contain.pop();
                    break;
                    
                case '}':
                    if(contain.empty() || contain.top() != '{')
                        return false;
                    
                    contain.pop();
                    break;
                    
                case ']':
                    if(contain.empty() || contain.top() != '[')
                        return false;
                    
                    contain.pop();
                    break;
                    
                default:
                    break;
            }
        }
        
        if(contain.empty())
            return true;
        else
            return false;
    }
};