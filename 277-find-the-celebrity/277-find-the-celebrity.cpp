/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        map<pair<int, int>, bool> m;
        int candidate = 0;
        
        for(int i = 0; i < n; i++) {
            bool res = knows(candidate, i);
            m[{candidate, i}] = res;
            if(res) candidate = i;
        }
        
        for(int i = 0; i < n; i++) {
            if(candidate != i) {
                bool res = false;
                if(m.find({candidate, i}) != m.end())
                    res |= m[{candidate, i}];
                else
                    res |= knows(candidate, i);
                
                if(m.find({i, candidate}) != m.end())
                    res |= !m[{i, candidate}];
                else
                    res |= !knows(i, candidate);
                
                if(res) return -1;
            }
        }
        
        return candidate;
    }
};