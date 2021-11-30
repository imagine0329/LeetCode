class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefixSum = 0;
        int len = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
            prefixSum += nums[i];
            if(prefixSum == k)
                len = i + 1;
            
            if(m.find(prefixSum - k) != m.end())
                len = max(len, i - m[prefixSum - k]);
            
            if(m.find(prefixSum) == m.end())
                m[prefixSum] = i;
        }
        
        return len;
    }
};