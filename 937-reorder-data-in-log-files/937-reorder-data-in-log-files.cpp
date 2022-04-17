/*
    - order: letter -> digit
    - sort letter logs
        if contents are the same, then sort lexicographically by their identifiers
    - maintain digit logs relative ordering
*/

struct Compare {
    bool operator()(string a, string b) {
        int a_i = a.find_first_of(" ");
        int b_i = b.find_first_of(" ");
        
        if(isdigit(a[a_i + 1]) && isdigit(b[b_i + 1]))
            return false;
        else if(!isdigit(a[a_i + 1]) && isdigit(b[b_i + 1]))
            return true;
        else if(isdigit(a[a_i + 1]) && !isdigit(b[b_i + 1]))
            return false;
        else {
            string a_id = a.substr(0, a_i);
            string b_id = b.substr(0, b_i);
            string a_content = a.substr(a_i);
            string b_content = b.substr(b_i);
            
            if(a_content == b_content)
                return a_id < b_id;
            return a.substr(a_i) < b.substr(b_i);
        }
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), Compare());
        return logs;
    }
};