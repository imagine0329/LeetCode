class Solution {
public:
    string strWithout3a3b(int a, int b) {
        return strWithout3a3b(a, b, 'a', 'b');
    }
    
    string strWithout3a3b(int A, int B, char a, char b) {
        if(A < B) return strWithout3a3b(B, A, b, a);
        
        string ans;
        while(A > 0) {
            ans += a;
            A--;
            if(A > B) {
                ans += a;
                A--;
            }
            if(B > 0) {
                ans += b;
                B--;
            }
        }
        
        return ans;
    }
};