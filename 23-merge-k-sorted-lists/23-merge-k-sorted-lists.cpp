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
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        
        for(auto l : lists) {
            if(l) q.push(l);
        }
            
        
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(!q.empty()) {
            auto top = q.top(); q.pop();
            node->next = top;
            node = node->next;
            if(top->next) q.push(top->next);
        }
        
        return dummy->next;
    }
};