class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> allocator;
        
        sort(intervals.begin(), intervals.end());
        allocator.push(intervals[0][1]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= allocator.top())
                allocator.pop();
            
            allocator.push(intervals[i][1]);
        }
        return allocator.size();
    }
};