class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(v.back() >= nums[i]) {
                int idx = binarySearch(v, nums[i]);
                v[idx] = nums[i];
            }
            else
                v.push_back(nums[i]);
        }
        
        return v.size() >= 3;
    }
    
    int binarySearch(vector<int>& v, int target) {
        int left = 0, right = v.size() - 1;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(v[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};