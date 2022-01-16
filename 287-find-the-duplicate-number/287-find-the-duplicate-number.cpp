class Solution {
private:
    int calcMaxBit(int n) {
        int bits = 0;
        while(n > 0) {
            n /= 2;
            bits++;
        }
        
        return bits;
    }
    
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = 0;
        int n = nums.size() - 1;
        int max_num = *max_element(nums.begin(), nums.end());
        int max_bit = calcMaxBit(max_num);
        
        for(int bit = 0; bit < max_bit; bit++) {
            int mask = 1 << bit;
            int base_count = 0, nums_count = 0;
            for(int i = 0; i <= n; i++) {
                if(i & mask)
                    base_count++;
                if(nums[i] & mask)
                    nums_count++;
            }
            
            if(base_count < nums_count)
                duplicate |= mask;
        }
        
        return duplicate;
        
    }
};