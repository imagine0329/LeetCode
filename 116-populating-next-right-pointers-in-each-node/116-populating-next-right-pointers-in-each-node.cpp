/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        traverse(root);
        return root;
    }
    
    void traverse(Node* root)
    {
        if(root == nullptr || root->left == nullptr || root->right == nullptr)
            return;
        
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : nullptr;
        
        traverse(root->left);
        traverse(root->right);
    }
};