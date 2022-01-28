class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int idx = 0;
        
        vector<int> v(nums.size());
        while(left <= right) {
            v[idx++] = nums[left];
            if(left != right)
                v[idx++] = nums[right];
            left++; right--;
        }
        
        nums = v;
    }
};