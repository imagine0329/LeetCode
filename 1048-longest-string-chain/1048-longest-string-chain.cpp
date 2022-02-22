struct Compare {
    bool operator()(const string& a, const string& b) {
        return a.length() < b.length();
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), Compare());
        unordered_map<string, int> memo;
        int longest = 1;
        for(int i = 0; i < words.size(); i++)
            longest = max(longest, recur(words, i, memo));
        return longest;
    }
    
    int recur(vector<string>& words, int curr, unordered_map<string, int>& memo) {
        if(curr == words.size()) return 0;
        if(memo.find(words[curr]) != memo.end()) return memo[words[curr]];
        
        int longest = 1;
        for(int i = curr + 1; i < words.size(); i++) {
            if(words[i].length() > words[curr].length() + 1)
                break;
            
            if(words[curr].length() + 1 == words[i].length() && isChain(words[curr], words[i]))
                longest = max(longest, recur(words, i, memo) + 1);
        }
        
        return memo[words[curr]] = longest;
    }
    
    bool isChain(const string& s1, const string& s2) {
        int l1 = s1.length(), l2 = s2.length();
        int p1 = 0, p2 = 0;
        
        while(p1 < l1 && p2 < l2) {
            if(s1[p1] != s2[p2])
                p2++;
            else {
                p1++; p2++;
            }
        }
        
        return (p1 == l1 && p2 == l2) || p1 == p2 ? true : false;
    }
};