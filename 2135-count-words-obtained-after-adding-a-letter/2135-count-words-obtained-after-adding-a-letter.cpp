class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> start;
        for(auto s : startWords) {
            int hash = 0;
            for(int i = 0; i < s.length(); i++)
                hash += (1 << (s[i] - 'a'));
            start.insert(hash);
        }
        
        int ans = 0;
        for(auto s : targetWords) {
            for(int k = 0; k < s.length(); k++) {
                int hash = 0;
                for(int i = 0; i < s.length(); i++) {
                    if(i == k)
                        continue;
                    hash += (1 << (s[i] - 'a'));
                }
                if(start.find(hash) != start.end()) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

/*

startWords = ["ant","act","tack"], targetWords = ["aack", "tack","act","acti"]

"aack" -> "ack" "aac" "aak"
"tack" -> "ack" "tck" "tak" "tac"
*/