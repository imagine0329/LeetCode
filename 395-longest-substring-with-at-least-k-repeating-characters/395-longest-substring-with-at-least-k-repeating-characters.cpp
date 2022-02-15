class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxUnique = getUniqueLetters(s);
        int longest = 0;
        
        for(int i = 0; i <= maxUnique; i++) {
            vector<int> count(26, 0);
            int start = 0, end = 0, unique = 0, unique_k = 0;
            while(end < s.length()) {
                if(unique <= i) {
                    int idx = s[end] - 'a';
                    if(count[idx] == 0)
                        unique++;
                    if(++count[idx] == k)
                        unique_k++;
                    end++;
                }
                else {
                    int idx = s[start] - 'a';
                    if(count[idx] == k)
                        unique_k--;
                    if(--count[idx] == 0)
                        unique--;
                    start++;
                }
                
                if(unique == i && unique_k == unique)
                    longest = max(longest, end - start);
            }
        }
        
        return longest;
    }

    int getUniqueLetters(string s) {
        unordered_set<char> unique;
        for(auto c : s)
            unique.insert(c);
        
        return unique.size();
    }
};