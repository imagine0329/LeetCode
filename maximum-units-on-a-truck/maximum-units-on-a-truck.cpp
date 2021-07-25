class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int idx, box;
        int units = 0;
        
        while(truckSize > 0)
        {
            idx = findMaxBox(boxTypes);
            if(idx == -1)
                break;
            
            box = boxTypes[idx][0];
            for(int i=0; i<boxTypes[idx][0] && truckSize>0; i++, box--)
            {
                units += boxTypes[idx][1];
                truckSize--;
            }
            
            boxTypes[idx][0] = box;
            if(box == 0)
                boxTypes[idx][1] = -1;
        }
        
        return units;
    }
    
    int findMaxBox(vector<vector<int>>& boxTypes)
    {
        int idx = -1;
        int max = -1;
        for(int i=0; i<boxTypes.size(); i++)
        {
            if(boxTypes[i][1] > max)
            {
                max = boxTypes[i][1];
                idx = i;
            }
        }
        
        return idx;
    }
};