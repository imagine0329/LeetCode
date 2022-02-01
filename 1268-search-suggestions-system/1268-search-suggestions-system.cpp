class Trie {
private:
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
        }
        node->isEnd = true;
    }
    
    vector<string> search(string s) {
        Trie* node = this;
        vector<string> result;
        
        for(auto c : s) {
            if(node->next[c - 'a'] == nullptr)
                return result;
            node = node->next[c - 'a'];
        }
        
        dfs(node, s, result);
        return result;
    }
    
    void dfs(Trie* node, string word, vector<string>& result) {
        if(result.size() == 3)
            return;
        if(node->isEnd)
            result.push_back(word);
        
        for(int i = 0; i < 26; i++) {
            if(node->next[i]) {
                word += i + 'a';
                dfs(node->next[i], word, result);
                word.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans(searchWord.length());
        
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