class WordDistance {
private:
    unordered_map<string, vector<int>> dict;
    
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i=0; i<wordsDict.size(); i++)
            dict[wordsDict[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0;
        int shortest = INT_MAX;
        
        while(i < dict[word1].size() && j < dict[word2].size()) {
            shortest = min(shortest, abs(dict[word1][i] - dict[word2][j]));
            dict[word1][i] < dict[word2][j] ? i++ : j++;
        }
        
        return shortest;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */