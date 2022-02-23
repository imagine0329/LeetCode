class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while(left < right) {
            int mid = (left + right) / 2;
            int spent = 0;
            
            for(auto pile : piles)
                spent += pile / mid + (pile % mid != 0);
            
            if(spent > h)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};