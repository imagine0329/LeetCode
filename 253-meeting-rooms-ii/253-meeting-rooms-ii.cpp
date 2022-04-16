class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        sort(intervals.begin(), intervals.end());
        
        q.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= q.top()) {
                q.pop();
            }
            q.push(intervals[i][1]);
        }
        
        return q.size();
    }
};