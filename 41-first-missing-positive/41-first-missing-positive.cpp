class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto n : nums)
        {
            if(n > 0)
                s.insert(n);
        }
        
        for(int i=1; i<s.size()+2; i++)
        {
            if(s.find(i) == s.end())
                return i;
        }
        
        return 0;
    }
};