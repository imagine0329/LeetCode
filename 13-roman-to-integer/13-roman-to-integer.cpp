class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0, curr = m[s[0]];
        int next;
        for(int i = 1; i < s.length(); i++) {
            next = m[s[i]];
            if(curr < next)
                ans -= curr;
            else
                ans += curr;
            curr = next;
        }
        return ans + curr;
    }
};