class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        
        while(left < right)
        {
            int mid = left + (right-left)/2;
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                break;
            else if(sum < target)
            {
                if(numbers[mid] + numbers[right] < target)
                    left = mid + 1;
                else
                    left++;
            }
            else
            {
                if(numbers[mid] + numbers[left] > target)
                    right = mid - 1;
                else
                    right--;
            }
        }
        
        return {left+1, right+1};
    }
};