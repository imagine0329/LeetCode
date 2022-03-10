class Trie {
public:
    Trie* next[26] = {nullptr};
    bool isWord = false;
    
    Trie() {}
    
    void insert(string s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isWord = true;
    }
    
    bool search(string s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(node->next[c] == nullptr) return false;
            node = node->next[c];
        }
        return node->isWord;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie* trie = new Trie();
        vector<string> ans;
        
        for(auto s : words)
            trie->insert(s);
        
        for(auto s : words) {
            if(dfs(trie, s)) ans.push_back(s);
        }
        return ans;
    }
    
    bool dfs(Trie* root, string s) {
        for(int i = 1; i < s.length(); i++) {
            string prefix = s.substr(0, i);
            if(root->search(prefix)) {
                string suffix = s.substr(i);
                if(root->search(suffix) || dfs(root, suffix)) return true;
            }
        }
        return false;
    }
};
