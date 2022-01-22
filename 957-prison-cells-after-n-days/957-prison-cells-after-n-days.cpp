class Solution {
private:
    int cellToBitmap(vector<int>& cells) {
        int ret = 0;
        for(auto c : cells)
            ret = (ret << 1) + c;
        
        return ret;
    }
    
    vector<int> nextDay(vector<int>& cells) {
        vector<int> temp(cells.size());
        temp[0] = 0;
        temp[cells.size()-1] = 0;
        for(int i = 1; i < cells.size()-1; i++)
            temp[i] = !(cells[i-1] ^ cells[i+1]);
        
        return temp;
    }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> seen;
        bool isFastForwarded = false;
        
        while(n > 0) {
            if(!isFastForwarded) {
                int state = cellToBitmap(cells);
                if(seen.find(state) != seen.end()) {
                    n %= seen[state] - n;
                    isFastForwarded = true;
                }
                else
                    seen[state] = n;
            }
            
            if(n > 0) {
                n--;
                cells = nextDay(cells);
            }
        }
        
        return cells;
    }
};