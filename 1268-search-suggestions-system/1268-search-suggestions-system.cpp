/*
1. parameters
    string array; product names
        -> list length
        -> string length
        -> all unique strings
        -> only lowercase
    string word; searched word
        -> word length
        -> only lowercase
2. returns
    each character typed
    
    word = "amazon"
    -> "a" -> "am" -> "ama" -> "amaz"
    string array<string array>
3. product names > 3
    return 3 lexicographically minimum words
    
*/
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());
        
        string str;
        vector<vector<string>> ans(searchWord.length());
        for(int i = 0; i < searchWord.length(); i++) {
            str += searchWord[i];
            int start = lower_bound(products.begin(), products.end(), str) - products.begin();
            for(int j = start; j < min(start + 3, n); j++) {
                if(products[j].find(str) == string::npos) 
                    break;
                ans[i].push_back(products[j]);
            }
        }
        
        return ans;
    }
};