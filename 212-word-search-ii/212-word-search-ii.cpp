class Trie {
public:
    Trie* next[26] = {nullptr};
    string* word = nullptr;
    
    Trie() {}
    void insert(string& s) {
        Trie* node = this;
        for(auto c : s) {
            c -= 'a';
            if(!node->next[c])
                node->next[c] = new Trie();
            
            node = node->next[c];
        }
        node->word = &s;
    }
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        
        for(auto& s : words)
            trie->insert(s);
        
        vector<string> ans;
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++)
                dfs(board, trie, ans, row, col);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, Trie* trie, vector<string>& ans, int row, int col) {
        if(board[row][col] == '#' || !trie->next[board[row][col] - 'a']) return;
        
        char org = board[row][col];
        trie = trie->next[org - 'a'];
        if(trie->word) {
            ans.push_back(*trie->word);
            trie->word = nullptr;
        }
        
        
        board[row][col] = '#';
        if(row - 1 >= 0) dfs(board, trie, ans, row - 1, col);
        if(row + 1 < board.size()) dfs(board, trie, ans, row + 1, col);
        if(col - 1 >= 0) dfs(board, trie, ans, row, col - 1);
        if(col + 1 < board[0].size()) dfs(board, trie, ans, row, col + 1);
        board[row][col] = org;
    }
};