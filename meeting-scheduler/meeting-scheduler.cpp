class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0, j = 0;
        
        while(i < slots1.size() && j < slots2.size())
        {
        //    if(slots1[i][0] < slots2[j][1] && slots1[i][1] > slots2[j][0])
        //    {
                int start = slots1[i][0] > slots2[j][0] ? slots1[i][0] : slots2[j][0];
                int end = slots1[i][1] < slots2[j][1] ? slots1[i][1] : slots2[j][1];
                
                if(end - start >= duration)
                    return {start, start + duration};
        //    }                
            
            if(slots1[i][1] < slots2[j][1])
                i++;
            else
                j++;
        }
        
        return {};
    }
};