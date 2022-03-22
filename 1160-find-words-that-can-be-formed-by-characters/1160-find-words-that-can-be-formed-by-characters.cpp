class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26);
        
        for(auto c : chars)
            cnt[c - 'a']++;
        
        int ans = 0;
        for(auto& w : words) {
            int match = true;
            vector<int> cnt_w(26);
            for(auto c : w) {
                if(++cnt_w[c - 'a'] > cnt[c - 'a']) {
                    match = false;
                    break;
                }
            }
            if(match)
                ans += w.length();
        }
        return ans;
    }
};