class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefix = 0;
        int longest = 0;
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            
            if(prefix == k)
                longest = i + 1;
            
            if(m.find(prefix - k) != m.end())
                longest = max(longest, i - m[prefix - k]);
            
            if(m.find(prefix) == m.end())
                m[prefix] = i;
        }
        
        return longest;
    }
};