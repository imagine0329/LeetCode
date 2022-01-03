class Trie {
private:
    Trie* next[26] = {};
    bool isEnd = false;
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* cur = this;
        for(auto c : word)
        {
            c -= 'a';
            if(cur->next[c] == nullptr)
                cur->next[c] = new Trie();
            cur = cur->next[c];
        }
        
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(auto c : word)
        {
            c -= 'a';
            if(cur->next[c] == nullptr)
                return false;
            cur = cur->next[c];
        }
        
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(auto c : prefix)
        {
            c -= 'a';
            if(cur->next[c] == nullptr)
                return false;
            cur = cur->next[c];
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