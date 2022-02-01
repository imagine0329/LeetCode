class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        vector<vector<string>> ans(searchWord.length());
        sort(products.begin(), products.end());
        
        string str = "";
        for(int i = 0; i < searchWord.length(); i++) {
            str += searchWord[i];
            int start = lower_bound(products.begin(), products.end(), str) - products.begin();
            for(int j = start; j < min(start + 3, n); j++) {
                if(products[j].find(str) == string::npos) break;
                ans[i].push_back(products[j]);
            }
        }
        
        return ans;
    }
};