class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
/*
                   i
    [[1,3],[2,6],[8,10],[15,18]]
                  s e1
               e2         
    [[1,6], [8,10]]
    
    if s <= e2
        e2 = max(e2, e1)
*/