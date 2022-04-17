class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<tuple<int, string, string>> order;
        unordered_map<string, vector<string>> m;
        unordered_map<string, int> freq;
        
        for(int i = 0; i < timestamp.size(); i++)
            order.push_back({timestamp[i], username[i], website[i]});
        
        sort(order.begin(), order.end());
        
        for(int i = 0; i < timestamp.size(); i++)
            m[get<1>(order[i])].push_back(get<2>(order[i]));
        
        for(auto v : m) {
            int n = v.second.size();
            if(n < 3)
                continue;
            
            unordered_set<string> s;
            for(int i = 0; i < n - 2; i++) {
                for(int j = i + 1; j < n - 1; j++) {
                    for(int k = j + 1; k < n; k++) {
                        s.insert(v.second[i] + " " + v.second[j] + " " + v.second[k] + " ");
                    }
                }
            }
            
            for(auto pattern : s)
                freq[pattern]++;
        }
        
        vector<string> v;
        int maxFreq = 0;
        for(auto f : freq) {
            if(f.second > maxFreq) {
                v.clear();
                v.push_back(f.first);
                maxFreq = f.second;
            }
            else if(f.second == maxFreq){
                v.push_back(f.first);
            }
        }
        
        sort(v.begin(), v.end());
        
        vector<string> ans;
        int start = 0;
        for(int i = 0; i < v[0].size(); i++) {
            if(v[0][i] == ' ') {
                ans.push_back(v[0].substr(start, i - start));
                start = i + 1;
            }
        }
        
        return ans;
    }
};