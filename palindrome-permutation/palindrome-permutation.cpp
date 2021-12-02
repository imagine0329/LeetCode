class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c : s)
            m[c]++;
        
        int odd = 0;
        for(auto n : m)
            odd += n.second % 2;
        
        return odd <= 1;
    }
};