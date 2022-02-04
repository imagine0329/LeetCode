class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int cycles = gcd(n, k);
        
        for(int i = 0; i < cycles; i++) {
            int j = i;
            int prev = nums[i];
            do {
                j = (j + k) % n;
                int temp = nums[j];
                nums[j] = prev;
                prev = temp;
            } while(j != i);
        }
    }
};