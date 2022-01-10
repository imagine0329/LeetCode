class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = -1, j = -1;
        
        while(i < n || j < m)
        {
            int v1 = 0, v2 = 0;
            while(i < n && isdigit(version1[++i]))
                v1 = (v1 * 10) + (version1[i] - '0');
            while(j < m && isdigit(version2[++j]))
                v2 = (v2 * 10) + (version2[j] - '0');
            
            if(v1 < v2)
                return -1;
            else if(v1 > v2)
                return 1;
        }
        
        return 0;
    }
};