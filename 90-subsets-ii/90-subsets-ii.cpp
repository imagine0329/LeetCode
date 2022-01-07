class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int p = 1 << n;
        vector<vector<int>> ans;
        unordered_set<string> seen;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<p; i++)
        {
            string hashcode;
            vector<int> subset;
            for(int j=0; j<n; j++)
            {
                if((i >> j) & 1)
                {
                    subset.push_back(nums[j]);
                    hashcode += to_string(nums[j]) + ',';
                }
            }
            
            if(seen.find(hashcode) == seen.end())
                {
                    ans.push_back(subset);
                    seen.insert(hashcode);
                }
        }
        
        return ans;
    }
    
};
