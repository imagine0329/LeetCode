class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        return diverse(a, b, c, 'a', 'b', 'c');
    }
    
    string diverse(int a, int b, int c, char A, char B, char C) {
        if(a < b) return diverse(b, a, c, B, A, C);
        if(b < c) return diverse(a, c, b, A, C, B);
        if(b == 0)
            return string(min(2, a), A);
        
        int use_a = min(2, a), use_b = b >= a - use_a ? min(2, b) : 1;
        return string(use_a, A) + string(use_b, B) + diverse(a - use_a, b - use_b, c, A, B, C);
    }
};