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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* first;
        ListNode* second;
        
        while(cur != NULL){
          first = cur->next;
          if(first ==  NULL) break;
          
          second = first->next;
          if(second == NULL) break;
          
          first->next = second->next;
          second->next = first;
          cur->next = second;
          
          cur = first;
        }
      
        return dummy->next;
    }
};