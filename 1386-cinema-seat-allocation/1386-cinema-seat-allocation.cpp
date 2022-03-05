class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> graph;
        
        for(auto seat : reservedSeats)
            graph[seat[0]] += 1 << seat[1];
        
        int ans = 0;
        for(auto it = graph.begin(); it != graph.end(); it++) {
            int reserved = it->second;
            int count = 0;
            if((reserved & 60) == 0) count++;
            if((reserved & 960) == 0) count++;
            if(((reserved & 240) == 0) && count == 0) count++;
            ans += count;
        }
        return ans + 2 * (n - graph.size());
    }
};