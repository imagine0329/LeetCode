class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        
        vector<vector<int>> ans;
        int i = 0;
        int n = items.size();
        while(i < n) {
            int id = items[i][0];
            int sum = 0;
            for(int k = i; k < i + 5; k++)
                sum += items[k][1];
            
            ans.push_back({id, sum / 5});
            
            while(i < n && items[i][0] == id)
                i++;
        }
        
        return ans;
    }
};