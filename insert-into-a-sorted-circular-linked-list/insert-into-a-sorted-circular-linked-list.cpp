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
        if(head == nullptr)
        {
            Node* temp = new Node(insertVal, nullptr);
            temp->next = temp;
            return temp;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        bool insert = false;
        
        do{
            if(prev->val <= insertVal && curr->val >= insertVal)
                insert = true;
            else if(prev->val > curr->val)
            {
                if(prev->val <= insertVal || curr->val >= insertVal)
                    insert = true;
            }
            
            if(insert)
            {
                Node* temp = new Node(insertVal, curr);
                prev->next = temp;
                return head;
            }
                
            prev = curr;
            curr = curr->next;
            
        }while(prev != head);
        
        prev->next = new Node(insertVal, curr);
        
        return head;
    }
};

