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
        ListNode *curr = head, *prev = nullptr, *next = head;
        ListNode* newHead = nullptr;
        
        while(curr) {
            int n = k;
            while(next && n > 0) {
                next = next->next;
                n--;
            }
                
            if(n != 0) {
                if(prev) prev->next = curr;
                break;
            }
            
            ListNode* reversed = reverseList(curr, k);
            if(!newHead) newHead = reversed;
            if(prev) prev->next = reversed;
            prev = curr;
            curr = next;
        }
        
        return newHead;
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