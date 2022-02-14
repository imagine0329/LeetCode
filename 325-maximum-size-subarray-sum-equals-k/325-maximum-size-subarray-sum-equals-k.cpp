class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        
        prefix[0] = 0;
        int sum = 0, longest = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(prefix.find(sum - k) != prefix.end())
                longest = max(longest, i - prefix[sum - k] + 1);
            if(prefix.find(sum) == prefix.end())
                prefix[sum] = i + 1;
        }
        
        return longest;
    }
};