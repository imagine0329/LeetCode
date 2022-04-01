class Trie {
public:
    Trie* next[26] = {nullptr};
    vector<string> words;
    
    Trie() {}
    
    void insert(string s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            node = node->next[c];
            node->words.push_back(s);
        }
    }
    
    vector<string> search(string s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr)
                return {};
            node = node->next[c];
        }
        return node->words;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        sort(products.begin(), products.end());
        
        for(auto p : products)
            trie->insert(p);
        
        vector<vector<string>> ans(searchWord.length());
        
        string str;
        for(int i = 0; i < searchWord.length(); i++) {
            str += searchWord[i];
            vector<string> ret = trie->search(str);
            int n = ret.size();
            for(int j = 0; j < min(3, n); j++)
                ans[i].push_back(ret[j]);
        }
        
        return ans;
    }
};