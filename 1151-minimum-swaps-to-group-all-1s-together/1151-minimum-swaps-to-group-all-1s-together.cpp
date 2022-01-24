class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(auto k : data)
            ones += k & 1;
        
        int count = 0, max_count = 0;
        deque<int> dq;
        for(auto i : data) {
            dq.push_back(i);
            count += i;
            if(dq.size() > ones) {
                count -= dq.front();
                dq.pop_front();
            }
            
            max_count = max(max_count, count);
        }
        
        return ones - max_count;
    }
};