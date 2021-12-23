class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> q;
        sort(intervals.begin(), intervals.end());
        
        for(auto i : intervals)
        {
            if(q.empty() || q.top() > i.front())
                q.push(i.back());
            else
            {
                q.pop();
                q.push(i.back());
            }
        }
        
        return q.size();
    }
};