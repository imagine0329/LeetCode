/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
    
    void serialize(TreeNode* root, stringstream& ss) {
        if(!root) {
            ss << "null ";
            return;
        }
        else
            ss << to_string(root->val) + " ";
        
        serialize(root->left, ss);
        serialize(root->right, ss);
    }
    
    TreeNode* deserialize(stringstream& ss) {
        string str;
        ss >> str;
        if(str == "null")
            return nullptr;
        
        int val = stoi(str);
        TreeNode* node = new TreeNode(val);
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));