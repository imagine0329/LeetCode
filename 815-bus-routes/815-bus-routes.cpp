class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int N = routes.size();
        unordered_map<int, vector<int>> graph;
        
        for(auto r : routes)
            sort(r.begin(), r.end());
        
        for(int i = 0; i < N - 1; i++) {
            for(int j = i + 1; j < N; j++) {
                if(intersect(routes[i], routes[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        queue<pair<int, int>> q;
        unordered_set<int> seen, targets;
        
        for(int i = 0; i < N; i++) {
            auto it = lower_bound(routes[i].begin(), routes[i].end(), source);
            if(it != routes[i].end() && *it == source) {
                q.push({i, 0});
                seen.insert(i);
            }
            
            it = lower_bound(routes[i].begin(), routes[i].end(), target);
            if(it != routes[i].end() && *it == target)
                targets.insert(i);
        }
        
        while(!q.empty()) {
            int bus = q.front().first, depth = q.front().second;
            q.pop();
            if(targets.find(bus) != targets.end()) return depth + 1;
            for(auto adj : graph[bus]) {
                if(seen.find(adj) == seen.end()) {
                    q.push({adj, depth + 1});
                    seen.insert(adj);
                }
            }
        }
        
        return -1;
    }
    
    bool intersect(vector<int>& r1, vector<int>& r2) {
        int i = 0, j = 0;
        while(i < r1.size() && j < r2.size()) {
            if(r1[i] == r2[j]) return true;
            if(r1[i] < r2[j])
                i++;
            else
                j++;
        }
        return false;
    }
};