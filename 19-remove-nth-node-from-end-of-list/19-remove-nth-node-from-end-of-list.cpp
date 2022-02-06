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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* node = head;
        
        while(node) {
            len++;
            node = node->next;
        }
        
        int k = len - n + 1;
        node = head;
        ListNode* prev = nullptr;
        while(--k) {
            prev = node;
            node = node->next;
        }
        
        if(prev)
            prev->next = node->next;
        else
            head = head->next;
        
        return head;
    }
};