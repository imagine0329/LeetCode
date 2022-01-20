/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        
        Node *prev = head, *curr = head->next;
        
        do{
            if(prev->val <= insertVal && curr->val >= insertVal)
                break;
            else if(prev->val > curr->val) {
                if(prev->val <= insertVal || curr->val >= insertVal)
                    break;
            }
            
            prev = curr;
            curr = curr->next;
        }while(prev != head);
        
        prev->next = new Node(insertVal, curr);
        return head;
    }
};