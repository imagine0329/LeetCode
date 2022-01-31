class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 1, k = 0;
        int count = 1;
        
        while(i <= chars.size()) {
            if(i == chars.size() || chars[i] != chars[i - 1]) {
                chars[k++] = chars[i - 1];
                if(count > 1) {
                    for(auto ch : to_string(count))
                        chars[k++] = ch;
                }
                count = 1;
            }
            else count++;
            i++;
        }
        
        return k;
    }
};