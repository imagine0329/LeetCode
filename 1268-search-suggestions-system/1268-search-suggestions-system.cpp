class Trie {
private:
    vector<string> words;
    Trie* next[26] = {nullptr};
    bool isEnd = false;
    
public:
    Trie() {
        
    }
    
    void insert(string s) {
        Trie* node = this;
        for(auto c : s) {
            if(node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
            node->words.push_back(s);
        }
        node->isEnd = true;
    }
    
    vector<string> search(string s) {
        Trie* node = this;
        for(auto c : s) {
            if(node->next[c - 'a'] == nullptr)
                return {};
            node = node->next[c - 'a'];
        }
        
        return node->words;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.length());
        
        sort(products.begin(), products.end());
        Trie* trie = new Trie();
        for(int i = 0; i < products.size(); i++)
            trie->insert(products[i]);
        
        for(int i = 1; i <= searchWord.length(); i++) {
            vector<string> v;
            v = trie->search(searchWord.substr(0, i));
            int n = v.size();
            for(int j = 0; j < min(3, n); j++)
                ans[i - 1].push_back(v[j]);
        }
        
        return ans;
    }
};