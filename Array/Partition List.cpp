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
    ListNode* partition(ListNode* head, int x) {
  		 ListNode *small = new ListNode(0), *greater = new ListNode(0), *p = head, *s = small, *g = greater;
  		 while (p) {
  		 	if (p->val < x) {
  		 		s->next = p;
  		 		s = s->next;
  		 	} else {
  		 		g->next = p;
  		 		g = g->next;
  		 	}
  		 	p = p->next;
  		 }
  		 s->next = greater->next;
  		 g->next = nullptr;
  		 return small->next;
    }
};