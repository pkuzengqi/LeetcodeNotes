/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        
        auto dummy=new ListNode(-1);
        dummy->next = head;
        
        auto p=dummy;
        for(int i=0;i<m-1;++i) p=p->next;
        ListNode *a = p, *b = a->next, *c = b->next;
        for (int i = m + 1; i <= n; i ++ )
        {
            auto d = c->next;
            c->next = b;
            b = c;
            c = d;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};
