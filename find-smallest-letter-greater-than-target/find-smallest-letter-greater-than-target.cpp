class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target)
            return letters.front();
        
        int left = 0, right = letters.size() - 1;
        
        while(left < right)
        {
            int mid = left + (right - left)/2;
            
            if(letters[mid] > target)
                right = mid;
            else
                left = mid + 1;
        }
        
        return letters[left];
    }
};