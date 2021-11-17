class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
        
        return ans;
    }
};