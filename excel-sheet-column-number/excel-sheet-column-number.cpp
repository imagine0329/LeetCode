class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;
        int power = 0;
        
        for(int i = columnTitle.length() - 1; i >= 0; i--)
            ret += pow(26, power++) * (columnTitle[i] - 'A' + 1);
        
        return ret;
    }
};