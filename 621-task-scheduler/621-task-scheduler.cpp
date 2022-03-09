class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto t : tasks)
            freq[t]++;
        
        priority_queue<int> pq;
        for(auto f : freq)
            pq.push(f.second);
        
        int totalTime = 0;
        int cycle = n + 1;
        while(!pq.empty()) {
            int time = 0;
            vector<int> temp;
            for(int i = 0; i < cycle && !pq.empty(); i++) {
                temp.push_back(pq.top());
                pq.pop();
                time++;
            }
            for(auto t : temp) {
                if(--t) pq.push(t);
            }
            
            totalTime += !pq.empty() ? cycle : time;
        }
        return totalTime;
    }
};