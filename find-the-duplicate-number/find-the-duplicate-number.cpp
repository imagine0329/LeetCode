class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*  Binary Search*/
        auto small_or_equal = [&](int cur)
        {
            int count = 0;
            for(auto &num : nums)
            {
                if(num <= cur)
                    count++;
            }
            
            return count;
        };
        
        int low = 1, high = nums.size();
        int duplicate;
        
        while(low <= high)
        {
            int cur = low + (high - low)/2;
            if(small_or_equal(cur) > cur)
            {
                duplicate = cur;
                high = cur - 1;
            }
            else
                low = cur + 1;
        }
        
        return duplicate;
        
        
        /*  Floyd's Cylcle Detection
        int tortoise = nums[0];
        int hare = nums[0];
        
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);
        
        tortoise = nums[0];
        while(tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return tortoise;*/
    }
};