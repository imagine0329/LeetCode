class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m;
        for(auto n2 : nums2)
            nums1[i++] = n2;
        
        sort(nums1.begin(), nums1.end());
    }
};