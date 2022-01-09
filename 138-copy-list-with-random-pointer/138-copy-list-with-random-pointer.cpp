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
        Node* newHead = nullptr;
        Node* old = head;
        Node* copied = nullptr;
        
        while(old)
        {
            Node* node = new Node(old->val);
            if(newHead == nullptr)
                newHead = node;
            
            node->next = old->next;
            old->next = node;
            old = node->next;
        }
        
        old = head;
        copied = newHead;
        while(copied)
        {
            copied->random = old->random ? old->random->next : nullptr;
            copied = copied->next ? copied->next->next : nullptr;
            old = old->next ? old->next->next : nullptr;
        }
        
        old = head;
        copied = newHead;
        while(old)
        {
            Node* copiedNext = copied->next;
            copied->next = copied->next ? copied->next->next : nullptr;
            old->next = copiedNext;
            
            old = old->next;
            copied = copied->next;
        }
        
        return newHead;
    }
};