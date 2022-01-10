class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int prev = lower - 1;
        
        for(int i=0; i<=nums.size(); i++)
        {
            int curr = (i == nums.size()) ? upper + 1 : nums[i];
            if(prev + 1 != curr)
                ans.push_back(formatString(prev+1, curr-1));
            
            prev = curr;
        }
        
        return ans;
    }
    
    string formatString(int lower, int upper)
    {
        if(lower == upper)
            return to_string(lower);
        
        return to_string(lower) + "->" + to_string(upper);
    }
};


