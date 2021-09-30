class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        
        for(int i : nums)
        {
            if(m.find(i) == m.end())
                m.insert(make_pair(i, 1));
            else
                m[i]++;
            
            if(m[i] > nums.size() / 2)
                return i;
        }
        
        return 0;
    }
};