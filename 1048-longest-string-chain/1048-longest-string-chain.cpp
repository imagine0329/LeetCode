struct Compare {
    bool operator()(string& a, string& b) {
        return a.length() < b.length();
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        sort(words.begin(), words.end(), Compare());
        unordered_map<string, int> dp;
        
        int longest = 1;
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].length(); j++) {
                string str = words[i].substr(0, j) + words[i].substr(j + 1);
                dp[words[i]] = max(dp[words[i]], dp.find(str) != dp.end() ? dp[str] + 1 : 1);
            }
            longest = max(dp[words[i]], longest);
        }
            
        return longest;
    }
};

/*
["a","b","ba","bca","bda","bdca"]

"a" -> "ba" -> "bca" -> "bdca"
"a" -> "ba" -> "bda" -> "bdca"

"a" ["b","ba","bca","bda","bdca"]
"ba" -> "a" "b"

"ba" ["bca","bda","bdca"]
"bca" -> "ca" "ba" "bc"
    
"bca" ["bda","bdca"]
"bdca" -> "dca" "bca" "bda" "bdc"

 0123
"bdca"
i = 0 ~ 3
substr(0,i) + substr(i + 1)
    i = 0 : "" + "dca"
    i = 1 : "b" + "ca"
    i = 2 : "bd" + "a"
    i = 3 : "bdc" + ""
*/