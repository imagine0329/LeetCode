
bool compare(const string a, const string b) {
    int i = a.find(' ') + 1, j = b.find(' ') + 1;

    if(isalpha(a[i]) && isalpha(b[j])) {
        if(a.substr(i) == b.substr(j))
            return a.substr(0, i - 1) < b.substr(0, j - 1);
        else
            return a.substr(i) < b.substr(j);
    }
    else {
        if(isalpha(a[i])) return true;
        else return false;
    }
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }
};