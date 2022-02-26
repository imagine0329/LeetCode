class NumArray {
private:
    vector<int> tree;
    vector<int> nums;
    
public:
    NumArray(vector<int>& nums) {
        tree = vector<int>(nums.size() + 1, 0);
        this->nums = nums;
        for(int i = 0; i < nums.size(); i++)
            init(i, nums[i]);
    }
    
    void init(int i, int val) {
        i++;
        while(i <= nums.size()) {
            tree[i] += val;
            i += (i & -i);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        init(index, diff);
    }
    
    int sumRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
    
    int getSum(int i) {
        int sum = 0;
        i++;
        while(i > 0) {
            sum += tree[i];
            i -= (i & -i);
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