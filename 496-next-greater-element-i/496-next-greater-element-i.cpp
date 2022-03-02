class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        
        for(int i = 0; i < nums2.size(); i++) {
            while(!s.empty() && s.top() < nums2[i]) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        
        while(!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        
        vector<int> ans;
        for(auto n : nums1)
            ans.push_back(m[n]);
        return ans;
    }
};