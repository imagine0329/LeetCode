class Codec {
public:
    string intToString(int n)
    {
        string str = to_string(n);
        string ret = "";
        
        for(int i=0; i<4-str.length(); i++)
            ret += "0";
        
        return ret + str;
    }

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        
        for(auto s : strs)
        {
            int len = s.length();
            ans += intToString(len);
            ans += s;
        }
        
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.length();
        
        while(i < n)
        {
            string temp = s.substr(i, 4);
            int len = stoi(temp);
            i += 4;
            ans.push_back(s.substr(i, len));
            i += len;
        }
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));