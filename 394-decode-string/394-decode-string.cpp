class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string ans;
        
        int k = 0;
        string currentString;
        
        for(auto c : s) {
            if(isdigit(c)) {
                k = k * 10 + c - '0';
            }
            else if(c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            }
            else if(c == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                for(int i = countStack.top(); i > 0; i--) {
                    decodedString = decodedString + currentString;
                }
                countStack.pop();
                currentString = decodedString;
            }
            else {
                currentString += c;
            }
        }
        
        return currentString;
    }
};
