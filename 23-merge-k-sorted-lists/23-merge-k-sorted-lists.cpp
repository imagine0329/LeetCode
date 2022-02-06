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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return mergeLists(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeLists(vector<ListNode*>& lists, int left, int right) {
        if(left == right)
            return lists[left];
        
        int mid = left + (right - left) / 2;
        ListNode* l = mergeLists(lists, left, mid);
        ListNode* r = mergeLists(lists, mid + 1, right);
        return merge(l, r);
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while(a && b) {
            if(a->val <= b->val) {
                node->next = a;
                a = a->next;
            }
            else {
                node->next = b;
                b = b->next;
            }
            
            node = node->next;
        }
        
        if(a)
            node->next = a;
        else if(b)
            node->next = b;
        
        return dummy->next;
    }
};