/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        
        Node* newHead = nullptr;
        Node* old = head;
        Node* copied = nullptr;
        
        while(old)
        {
            copied = new Node(old->val);
            copied->next = old->next;
            old->next = copied;
            old = copied->next;
        }
        
        old = head;
        while(old)
        {
            old->next->random = old->random ? old->random->next : nullptr;
            old = old->next->next;
        }
        
        old = head;
        newHead = head->next;
        copied = head->next;
        while(old)
        {
            old->next = old->next->next;
            copied->next = copied->next ? copied->next->next : nullptr;
            old = old->next;
            copied = copied->next;
        }
        
        return newHead;
    }
};