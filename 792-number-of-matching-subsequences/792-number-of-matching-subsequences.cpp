class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        
        vector<vector<int>> alpha(26);
        for(int i = 0; i < s.length(); i++)
            alpha[s[i] - 'a'].push_back(i);
        
        for(auto word : words) {
            int x = -1;
            bool found = true;
            
            for(auto c : word) {
                c -= 'a';
                auto it = upper_bound(alpha[c].begin(), alpha[c].end(), x);
                if(it == alpha[c].end()) {
                    found = false;
                    break;
                }
                x = *it;
            }
            if(found)
                count++;
        }
        return count;
    }
};
/*

s = "abbcde", words = ["a","bb","acd","ace"]

[a] = {0}
[b] = {1, 2}
[c] = {3}
[d] = {4}
[e] = {5}

"acd"
[a] -> 0
[c] -> 3
[d] -> 4

*/