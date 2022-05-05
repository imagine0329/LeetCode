class Trie {
private:
    Trie* next[27] = {nullptr};
    bool isEnd = false;
    string sentence;
    
public:
    void insert(string s) {
        Trie* node = this;
        for(auto c : s) {
            if(isspace(c))
                c = 26;
            else
                c -= 'a';
            
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            node = node->next[c];
        }
        node->isEnd = true;
        node->sentence = s;
    }
    
    vector<string> search(string s) {
        Trie* node = this;
        vector<string> result;
        
        for(auto c : s) {
            if(isspace(c))
                c = 26;
            else
                c -= 'a';
            
            if(node->next[c] == nullptr)
                return {};
            node = node->next[c];
        }
        
        dfs(node, result);
        return result;
    }
    
    void dfs(Trie* node, vector<string>& result) {
        if(node->isEnd)
            result.push_back(node->sentence);
        
        for(int i = 0; i < 27; i++) {
            if(node->next[i])
                dfs(node->next[i], result);
        }
    }
};

struct Compare {
    bool operator()(pair<int, string>& a, pair<int, string>& b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class AutocompleteSystem {
private:
    Trie* trie;
    unordered_map<string, int> m;
    string inputSentence;
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        
        for(int i = 0; i < sentences.size(); i++) {
            m[sentences[i]] = times[i];
            trie->insert(sentences[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            if(m.find(inputSentence) != m.end())
                m[inputSentence]++;
            else {
                trie->insert(inputSentence);
                m[inputSentence] = 1;
            }
            inputSentence = "";
            return {};
        }
        
        inputSentence += c;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        vector<string> result = trie->search(inputSentence);
        for(auto s : result)
            pq.push({m[s], s});
        
        vector<string> ans;
        while(!pq.empty() && ans.size() < 3) {
            ans.push_back(pq.top().second);
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

/*

[   5,             3,       2,              2]
["i love you", "island", "iroman", "i love leetcode"]

        0       1      2      3
input: ["i"], [" "], ["a"], ["#"]
0: i -> "i love you", "island", "i love leetcode"
1: i" " -> "i love you", "i love leetcode"
2: i a -> x
3: # -> end
    
inputSentence
        
        i
    " "         s           r
    l           l           o
    o           end         end
    v - start dfs
    e
    " "
y       l
o       e
u       e
end     t
        end

["i love you", "island", "iroman", "i love leetcode"]
max_heap
sorted by times and ascii-code order

for 0 to 26(alphabets + space)
*/