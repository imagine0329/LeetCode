class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        
        backtracking(k, n, ans, comb, 1);
        
        return ans;
    }
    
    void backtracking(int k, int remain, vector<vector<int>>& ans, vector<int>& comb, int start)
    {
        if(remain == 0 && comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }
        
        if(remain < 0 || comb.size() >= k)
            return;
        
        for(int i=start; i<=9; i++)
        {
            comb.push_back(i);
            backtracking(k, remain-i, ans, comb, i+1);
            comb.pop_back();
        }
            
    }
};