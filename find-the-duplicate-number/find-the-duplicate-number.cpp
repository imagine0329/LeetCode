class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        int ans;
        for(auto n : nums)
        {
            if(s.find(n) != s.end())
            {
                ans = n;
                break;
            }
            
            s.insert(n);
        }
        
        return ans;
    }
};