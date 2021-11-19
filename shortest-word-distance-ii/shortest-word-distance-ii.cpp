class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++)
            m[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0, dist = INT_MAX;
        
        while(i < m[word1].size() && j < m[word2].size())
        {
            dist = min(dist, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? i++ : j++;
        }
        
        return dist;
    }
private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */