class Solution {
public:
    
    static bool compare(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] > v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int i, remain = truckSize;
        int units = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        while(remain > 0 && i < boxTypes.size())
        {
            if(remain < boxTypes[i][0])
            {
                units += remain * boxTypes[i][1];
                remain = 0;
            }
            else
            {
                units += boxTypes[i][0] * boxTypes[i][1];
                remain -= boxTypes[i][0];
            }
            
            i++;
        }
        
        return units;
    }
};