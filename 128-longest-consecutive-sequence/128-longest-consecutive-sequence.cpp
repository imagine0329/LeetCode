class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        for(auto n : nums)
        {
            if(s.find(n-1) != s.end())
                continue;
            
            int x = n + 1;
            while(s.find(x) != s.end())
                x++;
            
            longest = max(longest, x-n);
        }
        
        return longest;
    }
    
};