class Solution {
private:
    vector<int> nums;
    int size;
    
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->size = nums.size();
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        
        vector<int> ans = nums;
        int left = size;
        
   //     srand(time(NULL));
        
        for(int i=size-1; i>=0; i--, left--)
        {
            int j = rand() % left;
            swap(ans[i], ans[j]);
        }
            
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */