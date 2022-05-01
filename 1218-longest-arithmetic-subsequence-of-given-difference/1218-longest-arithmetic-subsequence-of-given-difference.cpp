class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> len;
        
        int longest = 1;
        for(int i = 0; i < arr.size(); i++) {
            longest = max(longest, len[arr[i]] = 1 + len[arr[i] - difference]);
        }
        
        return longest;
    }
    
};

/*

[1, 5, 7, 8, 5, 3, 4, 2, 1]     difference = -2
[1, 3, 4, 0, 3, 2, 0, 0, 1]
    
1 -> -1
5 -> 3 -> 1
7 -> 5 -> 3
*/