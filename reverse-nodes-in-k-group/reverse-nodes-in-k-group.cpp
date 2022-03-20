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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        int count = 0;
        
        while(count < k && ptr) {
            ptr = ptr->next;
            count++;
        }
        
        if(count == k) {
            ListNode* reversed = reverseList(head, k);
            head->next = reverseKGroup(ptr, k);
            return reversed;
        }
        return head;
    }
    
    ListNode* reverseList(ListNode* node, int k) {
        ListNode *prev = nullptr;
        
        while(node && k--) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};