class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> unique;
        
        for(auto n : nums)
            m[n]++;
        for(auto n : m)
            unique.push_back(n.first);
        
        quickSelect(m, unique, unique.size() - k, 0, unique.size() - 1);
        return vector<int>(unique.end() - k, unique.end());
    }
    
    int partition(unordered_map<int, int>& m, vector<int>& unique, int left, int right) {
        int pivot = left + (right - left) / 2;
        swap(unique[pivot], unique[right]);
        
        int j = left;
        for(int i = left; i < right; i++) {
            if(m[unique[i]] <= m[unique[right]])
                swap(unique[i], unique[j++]);
        }
        
        swap(unique[j], unique[right]);
        return j;
    }
    
    void quickSelect(unordered_map<int, int>& m, vector<int>& unique, int k, int left, int right) {
        if(left == right) return;
        
        int pivot = partition(m, unique, left, right);
        if(pivot == k)
            return;
        if(pivot < k)
            quickSelect(m, unique, k, pivot + 1, right);
        else
            quickSelect(m, unique, k, left, pivot - 1);
    }
};