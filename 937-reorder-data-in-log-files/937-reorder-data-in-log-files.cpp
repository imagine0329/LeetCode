bool compare(string &a, string &b) {
    int i = a.find(' '), j = b.find(' ');
    
    if(a.substr(i + 1) == b.substr(j + 1))
        return a.substr(0, i) < b.substr(0, j);
    else
        return a.substr(i + 1) < b.substr(j + 1);
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters, digits;
        
        for(auto s : logs) {
            int i = s.find(' ');
            if(!isdigit(s[i + 1]))
                letters.push_back(s);
            else
                digits.push_back(s);
        }
        
        sort(letters.begin(), letters.end(), compare);
        
        for(auto s : digits)
            letters.push_back(s);
        
        return letters;
    }
};
