class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0, cnt_one = 0, max_one = 0;
        int left = 0, right = 0;
        
        for(auto d : data)
            ones += d;
        
        while(right < data.size()) {
            cnt_one += data[right++];
            if(right - left > ones) cnt_one -= data[left++];
            max_one = max(max_one, cnt_one);
        }
        
        return ones - max_one;
    }
};