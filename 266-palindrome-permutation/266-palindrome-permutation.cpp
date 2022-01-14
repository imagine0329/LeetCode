class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count = 0;
        
        for(int i=0; i<128 && count <= 1; i++) {
            int n = 0;
            for(int j=0; j<s.length(); j++) {
                if(s[j] == i)
                    n++;
            }
            
            count += n % 2;
        }
        
        return count <= 1;
    }
};

