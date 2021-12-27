class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        
        for(auto n : nums)
            s.insert(n);
        
        int i;
        for(i=1; i<s.size()+1; i++)
        {
            if(s.find(i) == s.end())
                return i;
        }
        
        return i;
    }
};