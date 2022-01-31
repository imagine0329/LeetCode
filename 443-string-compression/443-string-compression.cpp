class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, right = 0, k = 0;
        int count = 0;
        char c = chars[0];
        
        while(right < chars.size()) {
            if(chars[left] != chars[right]) {
                chars[k++] = c;
                if(count > 1) {
                    string temp = to_string(count);
                    for(auto ch : temp)
                        chars[k++] = ch;
                }
                
                left = right;
                c = chars[right];
                count = 1;
            }
            else
                count++;
            
            right++;
        }
        
        chars[k++] = c;
        if(count > 1) {
            string temp = to_string(count);
            for(auto ch : temp)
                chars[k++] = ch;
        }
        
        return k;
    }
};