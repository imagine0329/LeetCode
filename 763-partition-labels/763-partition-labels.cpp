class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        
        for(int i = 0; i < s.length(); i++)
            m[s[i]] = i;
        
        vector<int> ans;
        int start = 0;
        int rightmost = -1;
        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]] > rightmost)
                rightmost = m[s[i]];
            if(rightmost == i) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};