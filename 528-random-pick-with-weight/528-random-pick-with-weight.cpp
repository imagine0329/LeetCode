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
        for(int i = 0; i < prefix.size(); i++) {
            if(target < prefix[i])
                return i;
        }
        
        return prefix.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */