class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        for(auto t : tasks)
            freq[t - 'A']++;
        
        sort(freq.begin(), freq.end());
        int f_max = freq[25];
        int n_max = 0;
        
        for(auto f : freq) {
            if(f == f_max) n_max++;
        }
        
        return max((int)tasks.size(), (f_max - 1) * (n + 1) + n_max);
    }
};