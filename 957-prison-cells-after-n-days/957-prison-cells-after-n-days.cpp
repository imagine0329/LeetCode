class Solution {
private:
    int nextDay(int state) {
        state = ~(state << 1) ^ (state >> 1);
        state &= 0x7e;
        return state;
    }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> seen;
        bool isFastForwarded = false;
        
        int state = 0;
        for(auto c : cells) {
            state <<= 1;
            state |= c;
        }
        
        while(n > 0) {
            if(!isFastForwarded) {
                if(seen.find(state) != seen.end()) {
                    n %= seen[state] - n;
                    isFastForwarded = true;
                }
                else
                    seen[state] = n;
            }
            
            if(n > 0) {
                n--;
                state = nextDay(state);
            }
        }
        
        vector<int> ret(cells.size());
        for(int i = cells.size() - 1; i >= 0; i--) {
            ret[i] = state & 1;
            state >>= 1;
        }
        
        return ret;
    }
};