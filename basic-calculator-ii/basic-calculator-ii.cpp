class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        
        if(len == 0)
            return 0;
        
        stack<int> stack;
        int num = 0;
        char operation = '+';
        
        for(int i=0; i<len; i++)
        {
            char c = s[i];
            if(isdigit(c))
                num = (num * 10) + (c - '0');
            
            if(i == len-1 || (!isdigit(c) && !iswspace(c)))
            {
                if(operation == '+')
                    stack.push(num);
                else if(operation == '-')
                    stack.push(-num);
                else if(operation == '*')
                {
                    int n = stack.top();
                    stack.pop();
                    stack.push(n * num);
                }
                else if(operation == '/')
                {
                    int n = stack.top();
                    stack.pop();
                    stack.push(n / num);
                }
                
                operation = c;
                num = 0;
            }
        }
        
        int res = 0;
        while(stack.size() != 0)
        {
            res += stack.top();
            stack.pop();
        }
        
        return res;
    }
};