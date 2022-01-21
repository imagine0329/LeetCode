class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(auto n : nums)
            q.push(n);
        
        for(auto& n : nums) {
            n = q.top();
            q.pop();
        }
        
        return nums;
    }
};