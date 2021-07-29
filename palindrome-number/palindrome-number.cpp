class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        stack<char> s;
        int startPoint;
        
        for(int i=0 ;i<str.length()/2; i++)
        {
            s.push(str[i]);
        }
        
        if(str.length() % 2 == 0)
            startPoint = str.length() / 2;
        else
            startPoint = (str.length()/2) + 1;
        
        for(int i=startPoint; i<str.size(); i++)
        {
            if(s.empty())
                return true;
            
            if(s.top() != str[i])
                return false;
            else
                s.pop();
        }
        
        return true;
    }
};