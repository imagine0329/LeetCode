class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        int sum = 0;
        
        m[0]++;
        for(auto n : nums) {
            sum += n;
            if(m.find(sum - k) != m.end())
                count += m[sum - k];
            m[sum]++;
        }
        
        return count;
    }
};