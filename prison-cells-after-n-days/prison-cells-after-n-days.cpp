class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> seen;
        bool isFastForwarded = false;
        
        while(n)
        {
            if(!isFastForwarded)
            {
                int state = cellsToBitmap(cells);
                if(seen.find(state) != seen.end())
                {
                    n %= seen[state] - n;
                    isFastForwarded = true;
                }
                else
                    seen[state] = n;
            }
            
            if(n > 0)
            {
                n--;
                cells = nextDay(cells);
            }
        }
        
        return cells;
    }
    
    vector<int> nextDay(vector<int>& cells)
    {
        vector<int> newCells(cells.size());
        newCells[0] = 0;
        
        for(int i=1; i<cells.size()-1; i++)
            newCells[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
        
        newCells[cells.size()-1] = 0;
        
        return newCells;
    }
    
    int cellsToBitmap(vector<int>& cells)
    {
        int state = 0;
        
        for(auto i : cells)
        {
            state <<= 1;
            state |= i;
        }
        
        return state;
    }
};