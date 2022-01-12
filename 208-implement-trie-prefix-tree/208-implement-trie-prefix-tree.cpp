class Trie {
private:
    Trie* next[26] = {};
    bool isEnd = false;
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(auto c : word) {
            c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            
            node = node->next[c];
        }
        
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto c : word) {
            c -= 'a';
            if(node->next[c] == nullptr)
                return false;
                
            node = node->next[c];
        }
        
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto c : prefix) {
            c -= 'a';
            if(node->next[c] == nullptr)
                return false;
            
            node = node->next[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */