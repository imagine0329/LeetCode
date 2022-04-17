class Solution {
public:
    string intToRoman(int num) {
        vector<string> sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        int i = 0;
        string ans;
        while(i < sym.size()) {
            while(num >= val[i]) {
                int n = num / val[i];
                for(int j = 0; j < n; j++)
                    ans += sym[i];
                num %= val[i];
            }
            i++;
        }
        
        return ans;
    }
};