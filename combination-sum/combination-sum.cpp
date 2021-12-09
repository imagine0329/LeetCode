class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backTracking(ans, comb, candidates, target, 0);
        
        return ans;
    }
    
    void backTracking(vector<vector<int>>& ans, vector<int>& comb, vector<int>& candidates, int sum, int start)
    {
        if(sum == 0)
        {
            ans.push_back(comb);
            return;
        }   
        else if(sum < 0)
            return;
        
        for(int i = start; i<candidates.size(); i++)
        {
            comb.push_back(candidates[i]);
            backTracking(ans, comb, candidates, sum-candidates[i], i);
            comb.pop_back();
        }
    }
};


