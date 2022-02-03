class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> v(nums.end() - k, nums.end());
        v.insert(v.end(), nums.begin(), nums.end() - k);
        nums = v;
    }
    
};