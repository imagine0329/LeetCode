class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        ans.push_back(vector<int>());
        for(int num : nums)
        {
            vector<vector<int>> temp;
            vector<int> curr_temp;
            for(vector<int> curr : ans)
            {    
                curr_temp = curr;
                curr_temp.push_back(num);
                temp.push_back(curr_temp);
            }
            
            for(vector<int> curr : temp)
                ans.push_back(curr);
        }
        
        return ans;
    }
};