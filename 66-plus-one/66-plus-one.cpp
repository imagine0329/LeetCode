class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans = digits;
        int carry = 1;
        
        for(int i=ans.size()-1; i>=0; i--)
        {
            int x = ans[i] + carry;
            carry = x / 10;
            if(carry)
                x %= 10;
            
            ans[i]= x;
        }
        
        if(carry)
        {
            ans[0] = 1;
            ans.push_back(0);
        }
        
        return ans;
    }
};