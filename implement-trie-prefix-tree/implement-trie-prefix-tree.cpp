class Trie {
private:
    Trie* children[26] = {};
    bool isEndOfWord = false;
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        
        for(int i=0; i<word.length(); i++)
        {
            int index = word[i] - 'a';
            if(!node->children[index])
                node->children[index] = new Trie();
            
            node = node->children[index];
        }
        
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i=0; i<word.length(); i++)
        {
            int index = word[i] - 'a';
            if(!node->children[index])
                return false;
            
            node = node->children[index];
        }
        
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i=0; i<prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if(!node->children[index])
                return false;
            
            node = node->children[index];
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