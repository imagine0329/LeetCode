class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2)
            return {};
        
        vector<int> ans;
        unordered_map<int, int> m;
        sort(changed.begin(), changed.end());
        
        for(auto num : changed)
            m[num]++;
        
        for(auto num : changed) {
            if(m[num] == 0)
                continue;
            m[num]--;
            if(m.find(num * 2) != m.end() && m[num * 2] > 0) {
                m[num * 2]--;
                ans.push_back(num);
            }
            else
                return {};
        }
        
        return ans;
    }
};

/*
changed = [1,3,4,2,6,8]
[1,2,3,4,6,8]
{1, 3, 8}

key     val
1       true
2       true   v
3       true
4       true
6       true    v
8       true   v


    
[1,3,4,2,6,8,2,6,8]
*/

