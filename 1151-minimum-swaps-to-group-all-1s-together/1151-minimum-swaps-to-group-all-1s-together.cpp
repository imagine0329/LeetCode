class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(auto k : data)
            ones += k & 1;
        
        int count = 0, max_count = 0;
        int left = 0, right = 0;
        while(right < data.size()) {
            count += data[right++];
            if(right - left > ones)
                count -= data[left++];
            
            max_count = max(max_count, count);
        }
        
        return ones - max_count;
    }
};