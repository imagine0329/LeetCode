class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        
        for(auto i : intervals) {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int room = 0;
        for(int i=0, j=0; i<intervals.size(); i++) {
            if(start[i] < end[j])
                room++;
            else
                j++;
            
        }
        
        return room;
    }
};