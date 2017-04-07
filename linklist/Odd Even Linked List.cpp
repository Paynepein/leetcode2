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
    ListNode* oddEvenList(ListNode* head) {
    	if (!head || !head->next) return head;
  		ListNode *fakeHead = head->next, *curr = head, *next = fakeHead->next, *odd = head, *even = fakeHead;
  		while (next) {
  			curr->next = next;
  			next = next->next;
  			if (curr == odd) {
  				odd = odd->next;
  				curr = even;
  			} else {
  				even = even->next;
  				curr = odd;
  			}
  		}
  		odd->next = fakeHead;
  		if (curr == even) {
  			even->next = NULL;
  		}
  		return head;
    }
};