class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        
        for(auto arr : updates)
        {
            int startIdx = arr[0], endIdx = arr[1], inc = arr[2];
            
            ans[startIdx] += inc;
            if(endIdx < length - 1)
                ans[endIdx + 1] -= inc;
        }
        
        partial_sum(ans.begin(), ans.end(), ans.begin());
        
        return ans;
    }
};