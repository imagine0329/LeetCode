class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(int i=0; i<numbers.size(); i++)
        {
            int x = target-numbers[i];
            if(m.find(x) != m.end())
                return vector<int>{m[x], i+1};
            
            m[numbers[i]] = i + 1;
        }
        
        return ans;
    }
};