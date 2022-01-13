class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int shortest = INT_MAX;
        
        for(int i=0; i<wordsDict.size(); i++) {
            int j = -1;
            if(wordsDict[i] == word1)
                j = getWordIdx(wordsDict, word2, i+1);
            else if(wordsDict[i] == word2)
                j = getWordIdx(wordsDict, word1, i+1);
            
            if(j != -1)
                shortest = min(shortest, j - i);
        }
        
        return shortest;
    }
    
    int getWordIdx(vector<string>& wordsDict, string word, int start)
    {
        for(int i=start; i<wordsDict.size(); i++) {
            if(wordsDict[i] == word)
                return i;
        }
        
        return -1;
    }
};