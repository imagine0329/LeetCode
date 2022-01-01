class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> ban(banned.begin(), banned.end());
        
        for(auto& c : paragraph)
            c = isalpha(c) ? tolower(c) : ' ';
        
        istringstream iss(paragraph);
        pair<string, int> p("", 0);
        string w;
        while(iss >> w)
        {
            if(ban.find(w) == ban.end() && ++m[w] > p.second)
                p = make_pair(w, m[w]);
        }
        
        return p.first;
    }
};