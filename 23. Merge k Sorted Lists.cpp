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
  
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
      ListNode* head = new ListNode(0);
      ListNode* cur = head;
      while(l1!=NULL && l2!=NULL){
        if(l1->val < l2->val){
          cur->next = l1;
          l1 = l1->next;
        }
        else{
          cur->next = l2;
          l2=l2->next;
        }
        cur=cur->next;
      }
      cur->next = (l1!=NULL?l1:l2);
      return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size(), mid=n/2;
        if(n==0) return NULL;
        if(n==1) return lists[0];
        
        vector<ListNode*> left=vector<ListNode*>(lists.begin(),lists.begin()+mid);
        vector<ListNode*> right=vector<ListNode*>(lists.begin()+mid, lists.end());
        ListNode* l1=mergeKLists(left);
        ListNode* l2=mergeKLists(right);
        return merge2Lists(l1,l2);
    }
};