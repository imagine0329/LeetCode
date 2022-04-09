class Trie {
public:
    Trie* next[26] = { nullptr };
    string* word = nullptr;
    
    void insert(string& word) {
        Trie* node = this;
        for(auto c : word) {
            if(!node->next[c - 'a'])
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->word = &word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        Trie* trie = new Trie();
        
        for(auto& word : words)
            trie->insert(word);
        
        vector<string> ans;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++)
                dfs(board, trie, row, col, ans);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, Trie* trie, int row, int col, vector<string>& ans) {
        if(board[row][col] == '#' || !trie->next[board[row][col] - 'a'])
            return;
        
        char org = board[row][col];
        trie = trie->next[org - 'a'];
        if(trie->word) {
            ans.push_back(*trie->word);
            trie->word = nullptr;
        }
        
        board[row][col] = '#';
        if(row - 1 >= 0) dfs(board, trie, row - 1, col, ans);
        if(row + 1 < board.size()) dfs(board, trie, row + 1, col, ans);
        if(col - 1 >= 0) dfs(board, trie, row, col - 1, ans);
        if(col + 1 < board[0].size()) dfs(board, trie, row, col + 1, ans);
        board[row][col] = org;
    }
};