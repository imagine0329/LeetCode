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
        unordered_map<string, int> memo;
        
        int longest = 1;
        for(int i = 0; i < words.size(); i++)
            longest = max(longest, checkNext(dict, words[i], memo));
        
        return longest;
    }
    
    int checkNext(unordered_set<string>& dict, string word, unordered_map<string, int>& memo) {    
        if(memo.find(word) != memo.end())
            return memo[word];
        
        int longest = 1;
        for(int j = 0; j < word.length(); j++) {
            string str = word.substr(0, j) + word.substr(j + 1);
            if(dict.find(str) != dict.end())
                longest = max(longest, checkNext(dict, str, memo) + 1);
        }
        
        return memo[word] = longest;
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