class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int l1 = -1, l2 = -1;
        int shortest = INT_MAX;
        
        for(int i=0; i<wordsDict.size(); i++) {
            if(wordsDict[i] == word1)
                l1 = i;
            else if(wordsDict[i] == word2)
                l2 = i;
            
            if(l1 != -1 && l2 != -1)
                shortest = min(shortest, abs(l1 - l2));
        }
            
        return shortest;
    }
};