/*  Using Extra Array*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp = nums;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            int mod = (i+k) % n;
            nums[mod] = temp[i];
        }
    }
};

/*  Brute Force [TLE]
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i=0; i<k; i++)
        {
            int previous = nums.back();
            for(int j=0; j<nums.size(); j++)
            {
                int temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};*/