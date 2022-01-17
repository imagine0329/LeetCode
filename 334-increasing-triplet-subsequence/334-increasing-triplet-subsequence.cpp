class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(v.back() >= nums[i]) {
                for(auto& k : v) {
                    if(k >= nums[i]) {
                        k = nums[i];
                        break;
                    }
                }
            }
            else
                v.push_back(nums[i]);
        }
        
        return v.size() >= 3;
    }
    
    
};