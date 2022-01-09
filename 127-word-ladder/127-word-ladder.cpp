class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> dict;
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        
        for(auto s : wordList) {
            for(int i=0; i<beginWord.length(); i++) {
                string word = s;
                word[i] = '*';
                dict[word].push_back(s);
            }
        }
        
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while(!q.empty())
        {
            auto word = q.front().first;
            auto level = q.front().second;
            q.pop();
            
            for(int i=0; i<beginWord.length(); i++)
            {
                string newWord = word;
                newWord[i] = '*';
                
                for(auto s : dict[newWord])
                {
                    if(s == endWord)
                        return level + 1;
                    
                    if(visited.find(s) == visited.end())
                    {
                        visited.insert(s);
                        q.push({s, level+1});
                    }
                }
            }
        }
        
        return 0;
    }
};