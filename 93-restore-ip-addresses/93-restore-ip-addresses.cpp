class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> ans;
        
        for(int a = 1; a <= 3; a++) {
            for(int b = 1; b <= 3; b++) {
                for(int c = 1; c <= 3; c++) {
                    int d = n - a - b - c;
                    if(d > 0 && d <= 3 && a+b+c+d == n) {
                        int A = stoi(s.substr(0, a));
                        int B = stoi(s.substr(a, b));
                        int C = stoi(s.substr(a+b, c));
                        int D = stoi(s.substr(a+b+c, d));
                        if((a > 1 && s[0] == '0') || (b > 1 && s[a] == '0') ||
                           (c > 1 && s[a+b] == '0') || (d > 1 && s[a+b+c] == '0'))
                           continue;
                        if( ((a == 1 || s[0] != '0') && (b == 1 || s[a] != '0') &&
                            (c == 1 || s[a+b] != '0') && (d == 1 || s[a+b+c] != '0')) &&
                            (A <= 255 && B <= 255 && C <= 255 && D <= 255)) {
                            string ip = to_string(A) + '.' + to_string(B) + '.' +
                                to_string(C) + '.' + to_string(D);
                            ans.push_back(ip);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};