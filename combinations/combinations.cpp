class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backtracking(ans, comb, n, k, 1);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& comb, int n, int k, int idx)
    {
        if(comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }
        
        for(int i=idx; i<n+1; i++)
        {
            comb.push_back(i);
            backtracking(ans, comb, n, k, i+1);
            comb.pop_back();
        }
    }
};