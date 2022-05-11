class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> start, end;
        
        for(auto interval : intervals) {
            start.push(interval[0]);
            end.push(interval[1]);
        }
        
        int rooms = 0;
        while(!start.empty()) {
            int s = start.top(); start.pop();
            int e = end.top();
            
            if(s < e)
                rooms++;
            else
                end.pop();
        }
        return rooms;
    }
};

/*
[[0,30],[5,10],[15,20]]

r1    0                       30
r2        5   10
r2                15  20
    
                    i
start   0   5   15
end     10  20  30
            j
    
        start < end, need a room
        start > end, j++
*/