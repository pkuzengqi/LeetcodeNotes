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
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA, p2 = headB;
        while (p1 != p2)
        {
            if (p1) p1 = p1->next;
            else p1 = headB;
            if (p2) p2 = p2->next;
            else p2 = headA;
        }
        return p1;
    }
};

 //p1: a+c+b+c (a1,a2,c1,c2,c3,b1,b2,b3,c1,c2,c3)
 //p2: b+c+a+c (b1,b2,b3,c1,c2,c3,a1,a2,c1,c2,c3)