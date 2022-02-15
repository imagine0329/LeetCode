class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        
        for(auto n1 : nums1) {
            for(auto n2 : nums2)
                m[n1 + n2]++;
        }
        
        int count = 0;
        for(auto n3 : nums3) {
            for(auto n4 : nums4) {
                if(m.find(-n3 - n4) != m.end())
                    count += m[-n3 - n4];
            }
        }
        
        return count;
    }
};