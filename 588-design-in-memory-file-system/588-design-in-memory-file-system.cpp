class FileSystem {
private:
    class File {
    public:
        bool isFile;
        unordered_map<string, File*> m;
        string content = "";
        File() :isFile(false) {}
    };
    
    File* root;
    
public:
    FileSystem() {
        root = new File();
    }
    
    vector<string> ls(string path) {
        File* node = root;
        vector<string> files = getPath(path);
        for(auto f : files)
            node = node->m[f];
        if(node->isFile) return {files.back()};
        
        files.clear();
        for(auto f : node->m)
            files.push_back(f.first);
        
        sort(files.begin(), files.end());
        return files;
    }
    
    void mkdir(string path) {
        File* node = root;
        vector<string> files = getPath(path);
        for(auto f : files) {
            if(node->m.find(f) == node->m.end())
                node->m[f] = new File();
            node = node->m[f];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        File* node = root;
        vector<string> files = getPath(filePath);
        for(auto f : files) {
            if(node->m.find(f) == node->m.end())
                node->m[f] = new File();
            node = node->m[f];
        }
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        File* node = root;
        vector<string> files = getPath(filePath);
        for(auto f : files)
            node = node->m[f];
        return node->content;
    }
    
    vector<string> getPath(string path) {
        vector<string> ans;
        string str;
        path += '/';
        for(auto c : path) {
            if(c == '/' && str != "") {
                ans.push_back(str);
                str.clear();
            }
            else if(c != '/')
                str += c;
        }
        
        return ans;
    }
};



/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */