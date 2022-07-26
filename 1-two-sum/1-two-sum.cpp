class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];
            if(m.find(x) != m.end()) {
                ans.push_back(m[x]);
                ans.push_back(i);
                return ans;
            }
            m.insert({nums[i], i});
        }
        
        return ans;
    }
};

/*
target = 12
2   5   3   6   9
                i

map
key(remain)     val(index)
2               0
5               1
3               2 
6               3


x = target - nums[i] = 3
*/