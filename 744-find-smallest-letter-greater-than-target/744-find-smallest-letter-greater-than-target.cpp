class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while(left < right) {
            int mid = left + ((right - left) >> 1);
            if(letters[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        
        return letters[left] <= target ? letters[0] : letters[left];
    }
};