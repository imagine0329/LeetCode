class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(auto d : data)
            ones += d;
        
        int left = 0, right = 0;
        int max_one = 0;
        int cut_one = 0;
        
        while(right < data.size())
        {
            cut_one += data[right++];
            if(right - left > ones)
                cut_one -= data[left++];
            
            max_one = max(max_one, cut_one);
        }
        
        return ones - max_one;
    }
};