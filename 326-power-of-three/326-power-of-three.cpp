class Solution {
public:
    bool isPowerOfThree(int n) {
        double i = log10(n) / log10(3);
        double mod = fmod(i, 1);
        return mod == 0;
    }
};