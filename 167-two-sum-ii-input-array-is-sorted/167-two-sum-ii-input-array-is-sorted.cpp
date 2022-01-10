class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1, idx2;
        
        for(idx1 = 0; idx1 < numbers.size()-1; idx1++)
        {
            idx2 = search(numbers, target-numbers[idx1], idx1+1);
            if(idx2 != -1)
                return {idx1+1, idx2+1};
        }
        
        return {-1, -1};
    }
    
    int search(vector<int>& numbers, int target, int start)
    {
        int left = start, right = numbers.size()-1;
        
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(target == numbers[mid])
                return mid;
            else if(target < numbers[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }
};