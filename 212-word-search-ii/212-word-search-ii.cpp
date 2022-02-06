class Trie { 
public:
    Trie* next[26] = {nullptr};
    string* word = nullptr;
    
    Trie() {
        
    }
    
    void insert(string& word) {
        Trie* node = this;
        for(auto c : word) {
            c -= 'a';
            if(node->next[c] == nullptr)
                node->next[c] = new Trie();
            node = node->next[c];
        }
        node->word = &word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie* trie = new Trie();
        vector<string> ans;
        
        for(auto& s : words)
            trie->insert(s);
        
        for(int row = 0; row < m; row++)
            for(int col = 0; col < n; col++)
                dfs(board, trie, ans, row, col);
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, Trie* trie, vector<string>& ans, int row, int col) {
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n 
           || board[row][col] == '#' || trie->next[board[row][col] - 'a'] == nullptr)
            return;
        
        char org = board[row][col];
        trie = trie->next[org - 'a'];
        if(trie->word) {
            ans.push_back(*trie->word);
            trie->word = nullptr;
        }
        board[row][col] = '#';
        vector<int> offset = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int r = row + offset[i], c = col + offset[i + 1];
            dfs(board, trie, ans, r, c);
        }
        board[row][col] = org;
    }
};