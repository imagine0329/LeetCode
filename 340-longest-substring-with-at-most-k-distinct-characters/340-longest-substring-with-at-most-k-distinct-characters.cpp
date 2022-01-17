class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0, right = 0;
        int longest = 0;
        unordered_map<char, int> m;
        
        while(right < s.length()) {
            m[s[right]] = right;
            right++;
            
            if(m.size() > k) {
                int leftmost = INT_MAX;
                int key;
                for(auto n : m) {
                    if(leftmost > n.second) {
                        leftmost = n.second;
                        key = n.first;
                    }
                }
                
                left = leftmost + 1;
                m.erase(key);
            }
            
            longest = max(longest, right - left);
        }
        
        return longest;
    }
};

/*
So, the outer loop runs exactly N times, where N is the length of the string passed in. If you look at the behavior of the inner loop, it's basically a trailing pointer that is moving in as much as it needs to to produce a substring with an acceptable number of unique characters. If you assume k is a whole (non-negative number), the farthest right k can go is to i's position. In the worst case, the inner loop would run N iterations total, not each loop, but total. So, we can effectively treat this as another non-nested for-loop of N iterations, at most, if that makes thinking about it easier.
*/