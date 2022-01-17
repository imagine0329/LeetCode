class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            if(sub.back() < nums[i])
                sub.push_back(nums[i]);
            else {
                int idx = binarySearch(sub, nums[i]);
                sub[idx] = nums[i];
            }
        }
        
        return sub.size();
    }
    
    int binarySearch(vector<int>& sub, int target) {
        int left = 0, right = sub.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(sub[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};