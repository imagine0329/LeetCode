class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ip;
        backtracking(s, 0, ans, ip, 0);
        
        return ans;
    }
    
    void backtracking(string s, int start, vector<string>& ans, string& ip, int parts) {
        int n = s.length();
        if(parts == 4 && start == n) {
            ip.pop_back();
            ans.push_back(ip);
            return;
        }
        
        if(parts >= 4)
            return;
        
        for(int i = start; i < min(n, start + 3); i++) {
            if(valid(s, start, i)) {
                //ip.append(s.substr(start, i - start + 1));
                ip.push_back(s[i]);
                ip.push_back('.');
                backtracking(s, i + 1, ans, ip, parts + 1);
                ip.pop_back();
            }
        }
        
        int j = ip.length() - 1;
        while(j >= 0 && ip[j] != '.'){
            ip.pop_back();
            j--;
        }
    }
    
    bool valid(string s, int start, int end) {
        string temp = s.substr(start, end - start + 1);
        int ip = stoi(temp);
        
        if(s[start] == '0' && start != end) return false;
        if(ip > 255) return false;
        
        return true;
    }
};