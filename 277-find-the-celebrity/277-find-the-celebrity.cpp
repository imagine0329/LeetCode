/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            bool res = false;
            for(int j = 0; j < n; j++) {
                if(i != j)
                    res |= knows(i, j);
                if(res)
                    break;
            }
            if(!res) q.push(i);
        }
        
        if(q.size() == 0) return -1;
        
        while(!q.empty()) {
            auto i = q.front(); q.pop();
            bool res = true;
            for(int j = 0; j < n; j++) {
                if(i != j)
                    res &= knows(j, i);
                if(!res)
                    break;
            }
            if(res) return i;
        }
        
        return -1;
    }
};