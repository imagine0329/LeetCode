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
        if(lists.size() == 0) 
            return nullptr;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }
    
    ListNode* divideAndConquer(vector<ListNode*>& lists, int start, int end) {
        if(start == end) 
            return lists[start];
        if(start + 1 == end)
            return merge(lists[start], lists[end]);
            
        int mid = (start + end) / 2;
        ListNode* l1 = divideAndConquer(lists, start, mid);
        ListNode* l2 = divideAndConquer(lists, mid + 1, end);
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        if(!a || !b)
            return a ? a : b;
        
        ListNode* dummy = new ListNode(0);
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
        
        if(a) node->next = a;
        if(b) node->next = b;
        return dummy->next;
    }
};