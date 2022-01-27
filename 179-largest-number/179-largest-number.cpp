class Solution {
private:
    struct Comparator {
        bool operator()(const int& a, const int& b) {
            string s1 = to_string(a);
            string s2 = to_string(b);
            return stol(s1 + s2) > stol(s2 + s1);
        }
    };

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Comparator());
        if(nums[0] == 0) return "0";
        
        string ans;
        for(auto n : nums)
            ans += to_string(n);
        
        return ans;
    }
};