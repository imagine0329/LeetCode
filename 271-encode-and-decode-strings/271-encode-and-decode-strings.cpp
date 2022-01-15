

class Codec {
private:
    string intToString(int n) {
        string str = to_string(n);
        string ret;
        
        for(int i=0; i<4-str.length(); i++)
            ret += '0';
        
        return ret + str;
    }
    
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        for(auto s : strs)
            ret += intToString(s.length()) + s;
        
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        
        for(int i=0; i<s.length();) {
            string str = s.substr(i, 4);
            int len = stoi(str);
            i += 4;
            ret.push_back(s.substr(i, len));
            i += len;
        }
        
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));