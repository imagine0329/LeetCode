class FileSystem {
    class File {
    public:
        bool isFile = false;
        unordered_map<string, File*> files;
        string content = "";
    };
    
    File* root;
    
public:
    FileSystem() {
        root = new File();
    }
    
    vector<string> ls(string path) {
        vector<string> ans;
        vector<string> dirs = getPath(path);
        File* node = root;
        
        for(auto d : dirs)
            node = node->files[d];
        
        if(node->isFile)
            return {dirs.back()};
        
        for(auto f : node->files)
            ans.push_back(f.first);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        File* node = root;
        vector<string> dirs = getPath(path);
        for(auto d : dirs) {
            if(node->files.find(d) == node->files.end())
                node->files[d] = new File();
            node = node->files[d];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        File* node = root;
        vector<string> dirs = getPath(filePath);
        for(auto d : dirs) {
            if(node->files.find(d) == node->files.end())
                node->files[d] = new File();
            node = node->files[d];
        }
        
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        File* node = root;
        vector<string> dirs = getPath(filePath);
        for(auto d : dirs) {
            if(node->files.find(d) == node->files.end())
                return "";
            node = node->files[d];
        }
        return node->content;
    }
    
    vector<string> getPath(string path) {
        vector<string> ret;
        int i = 1, j = 1;
        
        while(j <= path.length()) {
            if(i != j && (j == path.length() || path[j] == '/')) {
                ret.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            j++;
        }
        return ret;
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