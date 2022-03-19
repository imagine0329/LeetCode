class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> unique;
        unordered_map<int, int> m;
        
        for(auto n : nums)
            m[n]++;
        
        for(auto e : m)
            unique.push_back(e.first);
        
        int n = unique.size();
        quickSelect(unique, m, 0, n - 1, n - k);
        return vector<int>(unique.begin() + n - k, unique.end());
    }
    
    void quickSelect(vector<int>& unique, unordered_map<int, int>& m, int left, int right, int k) {
        if(left == right) return;
        
        int pivot = left + (right - left) / 2;
        pivot = partition(unique, m, left, right, pivot);
        
        if(pivot == k) return;
        if(pivot < k) quickSelect(unique, m, pivot + 1, right, k);
        else quickSelect(unique, m, left, pivot - 1, k);
    }
    
    int partition(vector<int>& unique, unordered_map<int, int>& m, int left, int right, int pivot) {
        int store = left, i = left;
        swap(unique[pivot], unique[right]);
        
        while(i < right) {
            if(m[unique[i]] < m[unique[right]])
                swap(unique[store++], unique[i]);
            
            i++;
        }
        swap(unique[store], unique[right]);
        return store;
    }
};