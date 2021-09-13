/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;
    
    void inorder(Node* root)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left);
        
        if(last == nullptr)
        {
            first = root;
        }
        else
        {
            last->right = root;
            root->left = last;
        }
        
        last = root;
        
        inorder(root->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        inorder(root);
        
        last->right = first;
        first->left = last;
        
        return first;
    }
};