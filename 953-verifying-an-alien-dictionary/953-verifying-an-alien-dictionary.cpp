class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        
        for(int i = 0; i < order.length(); i++)
            m[order[i]] = i;
        
        for(int i = 0; i < words.size() - 1; i++) {
            if(m[words[i][0]] > m[words[i+1][0]])
                return false;
            else if(words[i][0] == words[i+1][0]){
                int last = min(words[i].length(), words[i+1].length()) - 1;
                for(int k = 1; k <= last; k++) {
                    if(m[words[i][k]] > m[words[i+1][k]])
                        return false;
                }
                if(words[i][last] == words[i+1][last] && words[i].length() > words[i+1].length())
                    return false;
            }
        }
        
        return true;
    }
};