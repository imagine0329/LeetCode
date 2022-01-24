class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int l1 = arr1.size(), l2 = arr2.size(), l3 = arr3.size();
        int i1 = 0, i2 = 0, i3 = 0;
        vector<int> ans;
        
        while(i1 < l1 && i2 < l2 && i3 < l3) {
            if(arr1[i1] == arr2[i2] && arr1[i1] == arr3[i3]) {
                ans.push_back(arr1[i1]);
                i1++; i2++; i3++;
            }
            else if(arr1[i1] < arr2[i2])
                i1++;
            else if(arr2[i2] < arr3[i3])
                i2++;
            else
                i3++;
        }
        
        return ans;
    }
};