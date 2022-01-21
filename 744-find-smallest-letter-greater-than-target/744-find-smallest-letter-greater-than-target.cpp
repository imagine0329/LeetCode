class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<bool> seen(26, false);
        for(auto c : letters)
            seen[c - 'a'] = true;
        
        while(seen[++target - 'a'] == false) {
            if(target > 'z')
                target = 'a' - 1;
        }
        
        return target;
    }
};