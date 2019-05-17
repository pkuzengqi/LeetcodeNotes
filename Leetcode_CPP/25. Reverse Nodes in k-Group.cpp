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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* cur = dummy;

        while (cur != NULL) {
            ListNode *first = cur -> next;
            ListNode *end = cur;

            for (int i = 0; i < k && end != NULL; i++)
                end = end -> next;

            if (end == NULL)
                break;

            ListNode *p1 = first;
            ListNode *p2 = first -> next;
            while (p1 != end) {
                ListNode *new_p2 = p2 -> next;
                p2 -> next = p1;
                p1 = p2;
                p2 = new_p2;
            }

            first -> next = p2;
            cur -> next = end;
            cur = first;
        }
        return dummy -> next;
    }
};

