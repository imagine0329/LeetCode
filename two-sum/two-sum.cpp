class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        int cur;
        int x;
        
        for(int i=0; i<nums.size(); i++)
        {
            cur = nums[i];
            x = target - cur;
            if(m.find(x) != m.end())
            {    
                result.push_back(m[x]);
                result.push_back(i);
                return result;
            }
            
            m.insert({cur, i});
        }
        
        
        return result;
    }
};