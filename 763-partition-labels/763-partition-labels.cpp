class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26);
        
        for(int i = 0; i < s.length(); i++)
            lastPos[s[i] - 'a'] = i;
        
        vector<int> ans;
        int last = 0, anchor = 0;
        for(int i = 0; i < s.length(); i++) {
            last = max(last, lastPos[s[i] - 'a']);
            if(last == i) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        
        return ans;
    }
};