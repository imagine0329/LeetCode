class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backtracking(ans, comb, k, n, 1);
        
        return ans;
    }
    
    void backtracking(vector<vector<int>>& ans, vector<int>& comb, int k, int remains, int idx)
    {
        if(comb.size() == k && remains == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        if(comb.size() > k || remains < 0 || idx > 9)
            return;
        
        for(int i=idx; i<10; i++)
        {
            comb.push_back(i);
            backtracking(ans, comb, k, remains-i, i+1);
            comb.pop_back();
        }
            
    }
};