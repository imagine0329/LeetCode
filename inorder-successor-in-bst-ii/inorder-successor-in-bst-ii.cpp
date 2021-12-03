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
        if(node-> right != nullptr)
        {
            Node* temp;
            node = node->right;
            while(node != nullptr)
            {
                temp = node;
                node = node->left;
            }
            
            return temp;
        }
        else
        {
            Node* temp = node;
            node = node->parent;
            while(node != nullptr && node->right == temp)
            {
                temp = node;
                node = node->parent;
            }
            
            return node;
        }
    }
};
