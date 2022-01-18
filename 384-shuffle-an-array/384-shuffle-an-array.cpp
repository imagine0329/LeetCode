class Solution {
private:
    vector<int> nums;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> ans = nums;
        int n = nums.size();
        
        for(int i = n-1; i > 0; i--, n--)
            swap(ans[i], ans[rand() % n]);
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */