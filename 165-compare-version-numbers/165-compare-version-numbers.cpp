class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        
        while(i < n || j < m)
        {
            int v1 = 0, v2 = 0;
            
            while(i < n && version1[i] != '.')
            {
                int x = version1[i] - '0';
                v1 = (v1 * 10) + x;
                i++;
            }
            
            while(j < m && version2[j] != '.')
            {
                int x = version2[j] - '0';
                v2 = (v2 * 10) + x;
                j++;
            }
            
            if(v1 < v2)
                return -1;
            else if(v1 > v2)
                return 1;
            
            i++;
            j++;
        }
        
        return 0;
    }
};