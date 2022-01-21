class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> m;
        
        int i = 0;
        
        while(i < paragraph.length()) {
            string str;
            while(i < paragraph.length() && isalpha(paragraph[i]))
                str += tolower(paragraph[i++]);
            
            if(str != "" && s.find(str) == s.end())
                ++m[str];
            
            i++;
        }
        
        string ans;
        int len = 0;
        for(auto n : m) {
            if(len < n.second) {
                ans = n.first;
                len = n.second;
            }
        }
        
        return ans;
    }
};