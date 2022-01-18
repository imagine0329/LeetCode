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
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        inorder(root);
        
        head->left = tail;
        tail->right = head;
        return head;
    }
    
    void inorder(Node* node) {
        if(node == nullptr)
            return;
        
        inorder(node->left);
        
        if(tail) {
            tail->right = node;
            node->left = tail;
        }
        else
            head = node;
        
        tail = node;
        
        inorder(node->right);
    }
};