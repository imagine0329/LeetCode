/*
1. parameters
    string array; product names
        -> list length
        -> string length
        -> all unique strings
        -> only lowercase
    string word; searched word
        -> word length
        -> only lowercase
2. returns
    each character typed
    
    word = "amazon"
    -> "a" -> "am" -> "ama" -> "amaz"
    string array<string array>
3. product names > 3
    return 3 lexicographically minimum words
    
*/

class Trie {
private:
    Trie* next[26] = {nullptr};
    bool isEnd = false;
    
public:
    Trie() {}
    
    void insert(string& s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
    }
    
    vector<string> search(string s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr)
                return {};
            node = node->next[c];
        }
        
        vector<string> result;
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
        Trie* trie = new Trie();
        sort(products.begin(), products.end());
        
        for(auto& s : products)
            trie->insert(s);
        
        vector<vector<string>> ans;
        string str;
        for(auto c : searchWord) {
            str += c;
            vector<string> words = trie->search(str);
            ans.push_back(words);
        }
        
        return ans;
    }
};