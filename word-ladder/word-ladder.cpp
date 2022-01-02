class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> all_combo_dict;
        int L = beginWord.length();
        
        for(auto s : wordList)
        {
            for(int i=0; i<L; i++)
            {
                string newWord = s;
                newWord[i] = '*';
                all_combo_dict[newWord].push_back(s);
            }
        }
        
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        
        q.push({beginWord, 1});
        visited.insert(beginWord);
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            string word = node.first;
            int level = node.second;
            
            for(int i=0; i<L; i++)
            {
                string newWord = word;
                newWord[i] = '*';
                for(auto s : all_combo_dict[newWord])
                {
                    if(s == endWord)
                        return level + 1;
                    
                    if(visited.find(s) == visited.end())
                    {
                        visited.insert(s);
                        q.push({s, level + 1});
                    }
                }
            }
        }
        
        return 0;
    }
};