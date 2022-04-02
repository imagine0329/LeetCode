class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one = 0, flip = 0;
        
        for(auto c : s) {
            if(c == '1')
                one++;
            else
                flip++;
            flip = min(one, flip);
        }
        return flip;
    }
};