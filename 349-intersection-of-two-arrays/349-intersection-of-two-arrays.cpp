class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int p1 = 0, p2 = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(p1 < nums1.size() && p2 < nums2.size()) {
            if(nums1[p1] == nums2[p2]) {
                if(v.empty() || v.back() != nums1[p1])
                    v.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if(nums1[p1] <= nums2[p2])
                p1++;
            else
                p2++;
        }
        
        return v;
    }
};