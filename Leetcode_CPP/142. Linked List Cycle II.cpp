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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return NULL;
        ListNode *fast=head, *slow=head;
        while(fast&&slow){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
            else return NULL;
            
            if(fast==slow){
                //first meet
                fast=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;//second meet
            }
        }
        return NULL;
    }
};
