/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *first = head, *second = head->next;
        while(second && second->next) {
            first = first->next;
            second = second->next->next;
        }
        
        second = reverseList(first->next);
        first->next = nullptr;
        first = head;
        while(first && second) {
            ListNode *next1 = first->next, *next2 = second->next;
            first->next = second;
            first = next1;
            second->next = first;
            second = next2;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};