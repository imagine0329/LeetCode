class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i1 = 0, i2 = 0;
        while(i1 < slots1.size() && i2 < slots2.size()) {
            int start = max(slots1[i1][0], slots2[i2][0]);
            int end = min(slots1[i1][1], slots2[i2][1]);
            if(end - start >= duration)
                return {start, start + duration};
            if(slots1[i1][1] < slots2[i2][1]) i1++;
            else i2++;
        }
        
        return {};
    }
};