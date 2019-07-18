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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        auto p=head;
        int n=0;
        while(p){ 
            p=p->next;
            ++n;
        }
        k%=n;
        if(!k) return head;
        
        p=head;
        while(k--&&p) p=p->next;
        auto q=head;
        while(p->next){
            p=p->next;
            q=q->next;
        }
        p->next=head;
        head=q->next;
        q->next=NULL;
        return head;
    }
};
