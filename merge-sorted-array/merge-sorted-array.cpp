class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        /*
        Method 1
        
        nums1.erase(nums1.begin() + m, nums1.end());
        
        for(int i=0; i<n; i++)
        {
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin(), nums1.end());
        */
        
        
        /*
        Method 2
        */
        int i = 0, j = 0, k = 0;
        vector<int> result(m+n);
        
        while(i<m && j<n)
        {
            if(nums1[i] <= nums2[j])
                result[k++] = nums1[i++];
            else
                result[k++] = nums2[j++];
        }
        
        while(i<m)
            result[k++] = nums1[i++];
        while(j<n)
            result[k++] = nums2[j++];
        
        for(i = 0; i < m+n; i++)
            nums1[i] = result[i];
    }
};