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
private: 
    ListNode* front;
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        ListNode* node = head;
        int len = 0;
        
        while(node) {
            len++;
            node = node->next;
        }
        
        if(len == 1)
            return true;
        
        int n;
        if(len & 1) n = len/2 + 1;
        else n = len/2;
        
        node = head;
        while(n--)
            node = node->next;
        
        ListNode* reversed = reverseNode(head, len/2);
        
        while(node && reversed) {
            if(node->val != reversed->val)
                return false;
            
            node = node->next;
            reversed = reversed->next;
        }
        
        return node == nullptr && reversed == nullptr;
    }
    
    ListNode* reverseNode(ListNode* head, int length) {
        ListNode* prev = nullptr;
        while(length--) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};