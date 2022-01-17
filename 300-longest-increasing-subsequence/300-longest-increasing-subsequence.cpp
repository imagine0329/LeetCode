class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            if(sub.back() < nums[i])
                sub.push_back(nums[i]);
            else {
                for(auto& s : sub) {
                    if(s >= nums[i]) {
                        s = nums[i];
                        break;
                    }
                }
            }
        }
        
        return sub.size();
    }
};