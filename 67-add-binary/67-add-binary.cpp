class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0;
        
        int i = a.length()-1, j = b.length()-1;
        while(i >= 0 || j >= 0)
        {
            int x = 0, y = 0;
            if(i >= 0)
                x = a[i--] - '0';
            if(j >= 0)
                y = b[j--] - '0';
            
            int sum = x + y + carry;
            if(sum & 2)
            {
                carry = 1;
                ret += sum - 2 + '0';
            }
            else
            {
                carry = 0;
                ret += sum + '0';
            }
        }
        
        if(carry)
            ret += "1";
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};