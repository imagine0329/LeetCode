class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0;
        
        for(auto c : s) {
            if(c == 'A') {
                late = 0;
                if(++absent > 1)
                    return false;
            }
            else if(c == 'L') {
                if(++late > 2)
                    return false;
            }
            else {
                late = 0;
            }
        }
        
        return true;
    }
};