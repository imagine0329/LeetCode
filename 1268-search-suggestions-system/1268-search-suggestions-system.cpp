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
    vector<string> words;
    
public:
    Trie() {}
    
    void insert(string& s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            node = node->next[c];
            node->words.push_back(s);
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
        return node->words;
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
            vector<string> v;
            int n = words.size();
            for(int i = 0; i < min(3, n); i++) {
                v.push_back(words[i]);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};