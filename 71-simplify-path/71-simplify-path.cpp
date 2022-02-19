class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        
        int i = 0;
        while(i < path.length()) {
            string temp;
            while(i < path.length() && path[i] != '/')
                temp += path[i++];
            
            if(temp == "..") {
                if(!dq.empty())
                    dq.pop_back();
            }
            else if(temp != "." && temp != "")
                dq.push_back(temp);
            i++;
        }
        if(dq.empty()) return "/";
        
        string ans;
        while(!dq.empty()) {
            ans += "/" + dq.front();
            dq.pop_front();
        }
        
        return ans;
    }
};