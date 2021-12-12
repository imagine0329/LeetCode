class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        /*  Sort*/
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i=0, j=0, k=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                nums1[k++] = nums1[i++];
                j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        
        return vector<int>(nums1.begin(), nums1.begin() + k);
        
        /*  First approach
        multiset<int> m(nums1.begin(), nums1.end());
        vector<int> ans;
        for(auto a : nums2)
        {
            multiset<int>::iterator it = m.find(a);
            if(it != m.end())
            {
                m.erase(it);
                ans.push_back(a);
            }
        }
        
        return ans;*/
        
        
        /*  Second approach - Hash Map
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> m;
        for(auto n : nums1)
            ++m[n];
        
        int k = 0;
        for(auto n : nums2)
        {
            auto it = m.find(n);
            if(it != m.end() && --(it->second) >= 0)
                nums1[k++] = n;
        }
        
        return vector(nums1.begin(), nums1.begin() + k);*/
    }
};