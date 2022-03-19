class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++) {
            int left = i + 1, right = numbers.size() - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                int sum = numbers[i] + numbers[mid];
                if(sum == target) return {i + 1, mid + 1};
                if(sum < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        
        return {};
    }
};