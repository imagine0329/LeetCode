class NumArray {
private:
    vector<int> nums;
    vector<int> blocks;
    int len;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        len = ceil(sqrt(nums.size()));
        blocks = vector<int>(len);
        for(int i = 0; i < nums.size(); i++)
            blocks[i / len] += nums[i];
    }
    
    void update(int index, int val) {
        int i = index / len;
        blocks[i] = blocks[i] - nums[index] + val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int start = left / len, end = right / len;
        
        if(start == end) {
            for(int i = left; i <= right; i++)
                sum += nums[i];
        }
        else {
            for(int i = left; i < (start + 1) * len; i++)
                sum += nums[i];
            for(int i = start + 1; i < end; i++)
                sum += blocks[i];
            for(int i = end * len; i <= right; i++)
                sum += nums[i];
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */