class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> odd;
        for(auto c : s) {
            if(odd.insert(c).second == false)
                odd.erase(c);
        }
        
        return odd.size() <= 1;
    }
};

