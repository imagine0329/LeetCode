class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        //  FOR each element of wordsDict
        //      STORE element and its index to map
        
        //  i = 0, j = 0;
        //  WHILE i < map[word1].size AND j < map[word2].size
        //      distance = smaller value among map[word1][i] and map[word2][j]
        //      IF map[word1][i] < map[word2][j]
        //          i++
        //      ELSE
        //          j++
        
        //  RETURN distance
        
        map<string, vector<int>> m;
        for(int i=0; i<wordsDict.size(); i++)
            m[wordsDict[i]].push_back(i);
            
        int i = 0, j = 0;
        int distance = INT_MAX;
        while(i < m[word1].size() && j < m[word2].size())
        {
            distance = min(distance, abs(m[word1][i]-m[word2][j]));
            if(m[word1][i] < m[word2][j])
                i++;
            else
                j++;
        }
        
        return distance;
    }
};