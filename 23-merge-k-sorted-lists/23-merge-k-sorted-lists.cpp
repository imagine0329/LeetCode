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
struct cmp {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto list : lists) {
            if(list) q.push(list);
        }
        
        if(q.empty()) return nullptr;
        
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while(!q.empty()) {
            ListNode* top = q.top(); q.pop();
            node->next = top;
            node = node->next;
            if(top->next) q.push(top->next);
        }
        
        return dummy->next;
    }
};