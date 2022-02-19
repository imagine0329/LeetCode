class Solution {
private:
    vector<int> prefix;
    
public:
    Solution(vector<int>& w) {
        for(auto n : w)
            prefix.push_back(n + (prefix.size() > 0 ? prefix.back() : 0));
    }
    
    int pickIndex() {
        int test = prefix.back();
        float target = ((float) rand() / RAND_MAX) * prefix.back();
        return binarySearch(target);
    }
    
    int binarySearch(float target) {
        int left = 0, right = prefix.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(prefix[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */