class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(auto i : intervals)
        {
            if(ans.size() == 0)
            {
                ans.push_back(i);
                continue;
            }    
            
            auto last = ans.back();
            if(last[1] >= i[0])
                ans.back()[1] = max(last[1], i[1]);
            else
                ans.push_back(i);
        }
        
        return ans;
    }
};