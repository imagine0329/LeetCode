class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int odd = 0;
        
        for(auto c : s) {
            if(++m[c] & 1) odd++;
            else odd--;
        }
        
        int n = s.length();
        if(((n & 1) && odd == 1) || (((n & 1) == 0) && odd == 0))
            return true;
        else
            return false;
    }
};

