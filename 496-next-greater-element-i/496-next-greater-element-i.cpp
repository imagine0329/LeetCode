class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size(); i++)
            m[nums2[i]] = i;
        
        vector<int> ans;
        for(auto n : nums1) {
            int i = m[n] + 1;
            while(i < nums2.size() && nums2[i] < n)
                i++;
            if(i == nums2.size()) ans.push_back(-1);
            else ans.push_back(nums2[i]);
        }
        
        return ans;
    }
};