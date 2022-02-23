class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> ans = {INT_MAX, 0};
        unordered_map<char, int> dict;
        unordered_map<char, int> window;
        
        for(auto c : t)
            dict[c]++;
        
        int formed = 0, required = dict.size();
        int left = 0, right = 0;
        
        while(right < s.length()) {
            char c = s[right];
            window[c]++;
            if(window[c] == dict[c]) formed++;
            
            while(left <= right && formed == required) {
                c = s[left];
                if(ans[0] > right - left + 1) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                }
                
                --window[c];
                if(dict.find(c) != dict.end() && window[c] < dict[c])
                    formed--;
                
                left++;
            }
            right++;
        }
        
        return ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]);
    }
};