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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* last = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        while(cur){
            next = cur -> next;
            cur -> next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};