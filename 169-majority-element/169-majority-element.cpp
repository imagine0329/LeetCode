class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = NULL;
        
        for(auto n : nums)
        {
            if(count == 0)
                candidate = n;
            
            count += candidate == n ? 1 : -1;
        }
        
        return candidate;
    }
};