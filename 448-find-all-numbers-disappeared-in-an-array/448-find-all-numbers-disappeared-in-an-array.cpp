class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        for(auto k : nums) {
            if(k == prev) continue;
            if(k != prev + 1)
                setRange(ans, prev + 1, k - 1);
            prev = k;
        }
        
        if(nums[n - 1] != n)
            setRange(ans, nums[n - 1] + 1, n);
        
        return ans;
    }
    
    void setRange(vector<int>& ans, int start, int end) {
        for(int i = start; i <= end; i++)
            ans.push_back(i);
    }
};