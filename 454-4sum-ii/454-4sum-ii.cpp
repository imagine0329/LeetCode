class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        vector<vector<int>> lists({nums1, nums2, nums3, nums4});
        addToHash(lists, m, 0, 0);
        return countComplements(lists, m, lists.size()/2, 0);
    }
    
    void addToHash(vector<vector<int>>& lists, unordered_map<int, int>& m, int i, int sum) {
        if(i == lists.size() / 2)
            ++m[sum];
        else {
            for(auto a : lists[i])
                addToHash(lists, m, i+1, sum + a);
        }
    }
    
    int countComplements(vector<vector<int>>& lists, unordered_map<int, int>& m, int i, int complement) {
        if(i == lists.size()) {
            auto it = m.find(complement);
            return it == m.end() ? 0 : it->second;
        }
        
        int cnt = 0;
        for(auto a : lists[i])
            cnt += countComplements(lists, m, i + 1, complement - a);
        
        return cnt;
    }
};