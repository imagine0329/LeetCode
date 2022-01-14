class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int odd = 0;
        
        for(auto c : s) {
            if(++m[c] & 1) odd++;
            else odd--;
        }
        
        return odd <= 1;
    }
};

