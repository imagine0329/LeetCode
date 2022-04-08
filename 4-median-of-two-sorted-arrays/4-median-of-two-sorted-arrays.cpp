class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = n1;
        while(lo <= hi) {
            int c1 = (lo + hi) / 2;
            int c2 = (n1 + n2) / 2 - c1;
            
            int l1 = c1 == 0 ? INT_MIN : nums1[c1 - 1];
            int l2 = c2 == 0 ? INT_MIN : nums2[c2 - 1];
            int r1 = c1 == n1 ? INT_MAX : nums1[c1];
            int r2 = c2 == n2 ? INT_MAX : nums2[c2];
            
            if(l1 > r2) hi = c1 - 1;
            else if(l2 > r1) lo = c1 + 1;
            else
                return (n1 + n2) % 2 ? min(r1, r2) : (max(l1, l2) + min(r1, r2)) * 0.5;
        }
        
        return -1;
    }
};