class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int i = 0;
        
        reverse(digits.begin(), digits.end());
        
        do{
            digits[i] += 1;
            if(digits[i] > 9)
            {
                carry = 1;
                digits[i] %= 10;
            }    
            else
                carry = 0;
            
            if(++i == digits.size())
            {
                if(carry == 1)
                    digits.push_back(1);
                
                break;
            }
            
        }while(carry != 0);
        
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};