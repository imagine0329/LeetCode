class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> v(26);
        for(int i=0; i<order.length(); i++)
            v[order[i] - 'a'] = i;
        
        for(int i=0; i<words.size()-1; i++)
        {
            for(int j=0; j<words[i].length(); j++)
            {
                if(j >= words[i+1].length())
                    return false;
                
                if(words[i][j] != words[i+1][j])
                {
                    int curr = words[i][j] - 'a';
                    int next = words[i+1][j] - 'a';
                    if(v[curr] > v[next])
                        return false;
                    else
                        break;
                }
            }
        }
        
        return true;
    }
};