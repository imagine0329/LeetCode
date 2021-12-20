class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int prev = lower - 1;
        
        for(int i=0; i<=nums.size(); i++)
        {
            int curr = i < nums.size() ? nums[i] : upper + 1;
            if(prev + 1 != curr)
                ans.push_back(formString(prev, curr));
            
            prev = curr;
        }
        
        return ans;
    }
    
    string formString(int i, int j)
    {
        int start = i + 1;
        int end = j - 1;
        if(start == end)
            return to_string(start);
        
        return to_string(start) + "->" + to_string(end);
    }
};


