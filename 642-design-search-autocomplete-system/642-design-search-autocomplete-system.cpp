class Trie {
private:
    Trie* next[27] = { nullptr };
    unordered_map<string, int> history;

public:
    Trie() {
        
    }
    
    void insert(string sentence, int times) {
        Trie* node = this;
        for(auto c : sentence) {
            if(isspace(c)) c = 26;
            else c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            
            if(node->next[c]->history.find(sentence) != node->next[c]->history.end())
                node->next[c]->history[sentence]++;
            else
                node->next[c]->history[sentence] = times;
            node = node->next[c];
        }
    }
    
    optional<unordered_map<string, int>> search(string s) {
        Trie* node = this;
        for(auto c : s) {
            if(isspace(c)) c = 26;
            else c -= 'a';
            if(node->next[c] == nullptr)
                return nullopt;
            node = node->next[c];
        }
        
        return node->history;
    }
};

class AutocompleteSystem {
private:
    Trie* trie = new Trie();
    string s = "";
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i = 0; i < sentences.size(); i++)
            trie->insert(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            trie->insert(s, 1);
            s.clear();
            return {};
        }
        s += c;
        auto history = trie->search(s);
        if(history == nullopt) return {};
        
        auto compare = [](pair<int, string>& a, pair<int, string>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(compare)> pq(compare);
        for(auto k : history.value()) {
            pq.push({k.second, k.first});
            if(pq.size() > 3)
                pq.pop();
        }
        
        vector<string> ans(pq.size());
        int i = pq.size() - 1;
        while(!pq.empty()) {
            ans[i--] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */