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
    
    bool checkNode(ListNode* current)
    {
        if(current) {
            if(!checkNode(current->next)) return false;
            if(current->val != front->val) return false;
            front = front->next;
        }
        
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        front = head;
        return checkNode(head);
    }
};