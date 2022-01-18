class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ret;
        
        for(auto n : nums2) {
            if(s.erase(n) > 0)
                ret.push_back(n);
        }
        
        return ret;
    }
};