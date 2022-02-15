/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return nullptr;
        
        if(node->right) {
            Node* leftmost = node->right;
            while(leftmost->left)
                leftmost = leftmost->left;
            return leftmost;
        }
        else if(node->parent) {
            if(node->parent->left == node)
                return node->parent;
            else {
                Node* temp = node->parent;
                while(temp->parent && temp != temp->parent->left)
                    temp = temp->parent;
                if(temp->parent && temp == temp->parent->left)
                    return temp->parent;
                else
                    return nullptr;
            }
        }
        else
            return nullptr;
    }
};