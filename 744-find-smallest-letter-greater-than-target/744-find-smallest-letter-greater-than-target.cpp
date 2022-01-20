class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if(idx == letters.size())
            return letters[0];
        
        return letters[idx];
    }
};