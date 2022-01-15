

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret;
        
        for(auto s : strs)
            ret += s + (char)258;
        
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        string str;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == (char)258) {
                ret.push_back(str);
                str.clear();
            }
            else
                str += s[i];
        }
        
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));