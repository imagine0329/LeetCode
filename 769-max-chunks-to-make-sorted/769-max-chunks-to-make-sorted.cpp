class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int max_val = arr[0];
        for(int i = 0; i < arr.size(); i++) {
            max_val = max(max_val, arr[i]);
            if(max_val == i)
                count++;
        }
        
        return count;
    }
};