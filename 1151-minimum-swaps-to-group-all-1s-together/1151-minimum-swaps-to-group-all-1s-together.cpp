class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        
        for(auto n : data)
            ones += n;
        
        int left = 0, right = 0;
        int cnt_ones = 0, max_ones = 0;
        while(right < data.size()) {
            cnt_ones += data[right++];
            if(right - left > ones)
                cnt_ones -= data[left++];
            max_ones = max(max_ones, cnt_ones);
        }
        return ones - max_ones;
    }
};