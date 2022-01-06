class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans = digits;
        int carry = 0;
        
        ans.back() += 1;
        if(ans.back() / 10)
        {
            carry = 1;
            ans.back() %= ans.back();
        }
        else
            return ans;
        
        for(int i=ans.size()-2; i>=0; i--)
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