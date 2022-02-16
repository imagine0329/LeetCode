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
        if(!head) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        
        Node *prev = head, *next = head->next;
        while(head != next) {
            if(prev->val <= insertVal && next->val >= insertVal)
                break;
            else if(prev->val > next->val) {
                if(prev->val <= insertVal || next->val >= insertVal)
                    break;
            }
            
            prev = next;
            next = next->next;
        }
        
        prev->next = new Node(insertVal, next);
        return head;
    }
};