class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        sort(candidates.begin(), candidates.end());
        backtracking(ans, comb, candidates, target, 0);
        
        return ans;
    }
    
    bool backtracking(vector<vector<int>>& ans, vector<int>& comb, vector<int>& candidates, int remains, int idx)
    {
        if(remains == 0)
        {
            ans.push_back(comb);
            return true;
        }
        
        if(remains < 0 || idx == candidates.size())
            return false;
        
        unordered_set<int> s;
        for(int i=idx; i<candidates.size(); i++)
        {
            if(s.count(candidates[i]) == 1)
                continue;
            
            s.insert(candidates[i]);
            comb.push_back(candidates[i]);
            backtracking(ans, comb, candidates, remains-candidates[i], i+1);
            comb.pop_back();
        }
        
        return true;
    }
};