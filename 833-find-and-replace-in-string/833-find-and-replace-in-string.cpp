class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < indices.size(); i++)
            m[indices[i]] = i;
        
        sort(indices.begin(), indices.end());
        
        string ans;
        int curr = 0;
        for(auto index : indices) {
            int i = m[index];
            int next = index + sources[i].length();
            if(sources[i] != s.substr(index, sources[i].length()))
                continue;
            ans += s.substr(curr, index - curr);
            ans += targets[i];
            curr = next;
        }
        
        ans += s.substr(curr);
        return ans;
    }
};
/*
       c
s = "abcdef"
              i
indices = [0, 4]
sources = ["ab", "ec", "ef"]
targets = ["aaa", "bbb", "ccc"]

next = i + source.len
c..i + target
c = next
c..i + target

*/